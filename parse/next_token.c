/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:34:05 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 20:08:26 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	lexer_int(char *line)
{
	t_lexer	lexer;

	lexer.line = line;
	lexer.pos = 0;
	lexer.error = 0;
	return (lexer);
}

static t_token	token_check(t_lexer *lexer, char *str, t_type type)
{
	if (!ft_strncmp(lexer->line, str, ft_strlen(str)))
		return (token_int(type, str, ft_strlen(str)));
	return (lexer->error = L_EOT, token_int(ERROR, NULL, 0));
}

static t_token	string_check(t_lexer *lexer)
{
	char	*str;
	int		i;
	int		mode;

	i = 0;
	mode = UNQUOTED;
	str = lexer->line;
	while (str[i] && (mode != UNQUOTED || !ft_strchr(METACH, str[i])))
		mode = enc_switch_mode(mode, str[i++]);
	if (i == 0)
		return (lexer->error = L_EOT, token_int(ERROR, NULL, 0));
	if (mode != UNQUOTED)
		return (lexer->error = L_EOF, token_int(ERROR, NULL, 0));
	return (token_int(STR, lexer->line, i));
}

t_token	next_token(t_lexer *lexer)
{
	t_token	token;

	token = token_check(lexer, "|", PIPE);
	if (token.type == ERROR)
		token = token_check(lexer, "<<", l_R_I);
	if (token.type == ERROR)
		token = token_check(lexer, "<", l_I);
	if (token.type == ERROR)
		token = token_check(lexer, ">>", l_R_O);
	if (token.type == ERROR)
		token = token_check(lexer, ">", l_O);
	if (token.type == ERROR)
		token = string_check(lexer);
	return (token);
}
