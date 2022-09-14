/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:12:52 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 10:55:16 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_glob(char *str)
{
	int	mode;

	mode = UNQUOTED;
	while (*str)
	{
		if (mode == UNQUOTED && *str == '*')
			return (1);
		mode = enc_switch_mode(mode, *str);
		str++;
	}
	return (0);
}

static int	glob_match_rec(char *str, const char *d_name, int mode)
{
	const char	*d_start = d_name;

	while (1)
	{
		while (*str == ENC_SQ || *str == ENC_DQ)
			mode = enc_switch_mode(mode, *str++);
		if (*str == '\0')
			return (*d_name == '\0');
		else if (mode == UNQUOTED && *str == '*')
		{
			while (*str == ENC_SQ || *str == ENC_DQ
				|| (mode == UNQUOTED && *str == '*'))
					mode = enc_switch_mode(mode, *str++);
			if ((*d_name == '.' && d_name == d_start) || *str == '/')
				return (0);
			if (*str == '\0')
				return (1);
			while (*d_name != '\0')
				if (glob_match_rec(str, d_name++, mode))
					return (1);
			return (0);
		}
		else if (*str++ != *d_name++)
			return (0);
	}
}

static t_list	*is_match(char *str)
{
	t_list			*lst;
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(".");
	if (!dirp)
		return (NULL);
	dp = readdir(dirp);
	lst = NULL;
	while (dp)
	{
		if (glob_match_rec(str, dp->d_name, UNQUOTED)
			&& !lst_put_orderly(&lst, dp->d_name))
			break ;
		dp = readdir(dirp);
	}
	return (closedir(dirp), lst);
}

t_list	*parse_glob(t_token token)
{
	t_list	*glob;
	char	*str;

	str = ft_substr(token.str, 0, token.len);
	if (!str)
		return (perror("minishell"), NULL);
	glob = NULL;
	errno = 0;
	if (is_glob(str))
		glob = is_match(str);
	if (!glob && (errno != 0 || !lst_put_orderly(&glob, enc_rm_quotes(str))))
		perror("minishell");
	return (free(str), glob);
}
