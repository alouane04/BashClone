/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:27:02 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/14 13:52:18 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static	int	write_heredoc_line(char *file, int fd, char *line, bool expa)
{
	char	*env;

	env = NULL;
	if (expa)
	{
		env = expand(line);
		if (!env)
			return (close(fd), unlink(file), free(file), free(line), -1);
		return (ft_putstr_fd(env, fd), ft_putchar_fd('\n', fd), free(env), 0);
	}
	return (ft_putstr_fd(line, fd), ft_putchar_fd('\n', fd), 0);
}

static	int	read_heredoc(char *file, char *delime, bool expand)
{
	char	*line;
	int		fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd(file, 2),
			ft_putstr_fd(": ", 2), perror(NULL), fd);
	line = readline("> ");
	while (line)
	{
		if (!strcmp(line, delime))
			break ;
		if (write_heredoc_line(file, fd, line, expand))
			return (-1);
		free(line);
		line = readline("> ");
	}
	return (free(line), close(fd), 0);
}

static char	*r_i_filename(t_token str)
{
	static int	n = 0;
	char		*n_str;
	char		*delim;
	char		*file;
	bool		expand;

	expand = !ft_memchr(str.str, ENC_SQ, str.len);
	expand = (expand && !ft_memchr(str.str, ENC_DQ, str.len));
	n_str = ft_itoa(n);
	delim = ft_substr(str.str, 0, str.len);
	if (delim)
		enc_rm_quotes(delim);
	if (n_str)
		file = ft_strjoin("/tmp/minishell-heredoc-", n_str);
	free(n_str);
	if (!delim || !n_str || !file || read_heredoc(file, delim, expand))
		return (perror("minishell"), free(delim), free(file), NULL);
	return (free(delim), n++, file);
}

static char	*filename(t_token str)
{
	t_list	*file;
	char	*s;

	file = parse_glob(str);
	if (!file)
		return (NULL);
	if (ft_lstsize(file) != 1)
		return (ft_putstr_fd("error redirection in: ", 2),
			ft_putstr_fd(str.str, 2), ft_lstclear(&file), NULL);
	s = file->content;
	return (free(file), s);
}

t_rdr	*rdr_int(t_rdr_type rdr_type, t_token str)
{
	t_rdr	*rdr;

	rdr = malloc(sizeof(t_rdr));
	if (!rdr)
		return (perror("minishell"), NULL);
	rdr->type = rdr_type;
	if (rdr_type == R_I)
		rdr->rdr = r_i_filename(str);
	else
		rdr->rdr = filename(str);
	if (!rdr->rdr)
		return (free(rdr), NULL);
	return (rdr);
}
