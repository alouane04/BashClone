/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:09 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/16 19:46:16 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "minishell.h"
#include "lib_env/env.h"

#define NOT_FOUND ((char *)-1)

static char	*expand_exit(char **line)
{
	if (strncmp(*line, "$?", 2))
		return (NOT_FOUND);
	return (*line += 2, ft_itoa(g_shell.exit_s));
}

static char	*expand_env(char **line)
{
	char	*value;
	char	*s;
	int		i;

	i = 0;
	s = *line;
	if (s[i++] != '$' || (!ft_isalpha(s[i]) && (s[i] != '_')))
		return (NOT_FOUND);
	s++;
	while (ft_isalnum(s[i]) || s[i] == '_')
		i++;
	*line = s + i;
	value = get_env_n(s, i);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static char	*expand_char_add(char *s, char *exp)
{
	char	*join;

	join = NULL;
	if (exp)
		join = ft_strjoin(s, exp);
	return (free(s), free(exp), join);
}

static char	*expand_char(char *s, char c)
{
	char	str[2];
	char	*join;

	str[0] = c;
	str[1] = '\0';
	join = ft_strjoin(s, str);
	return (free(s), join);
}

char	*expand(char *line)
{
	int		mode;
	char	*s;
	char	*exp;

	mode = UNQUOTED;
	s = ft_strdup("");
	while (s && *line)
	{
		exp = NOT_FOUND;
		mode = enc_switch_mode(mode, *line);
		if (mode != S_QUOTED)
		{
			exp = expand_exit(&line);
			if (exp == NOT_FOUND)
				exp = expand_env(&line);
		}
		if (exp == NOT_FOUND)
			s = expand_char(s, *line++);
		else
			s = expand_char_add(s, exp);
	}
	if (!s)
		perror("minishell");
	return (s);
}
