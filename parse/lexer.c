/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:21:03 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 08:51:17 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	token_int(t_type type, char *str, int len)
{
	t_token	token;

	token.str = str;
	token.type = type;
	token.len = len;
	return (token);
}

void	lexer_advence(t_lexer *lexer, int n)
{
	n = ft_strnlen(lexer->line, n);
	lexer->line += n;
	lexer->pos = n;
}

static void	skip_spaces(t_lexer *lexer)
{
	int	n;

	n = 0;
	while (lexer->line[n] == ' ')
		n++;
	lexer_advence(lexer, n);
}

t_token	token_peak(t_lexer *lexer)
{
	skip_spaces(lexer);
	if (!*lexer->line)
		return (token_int(EOF_T, NULL, 0));
	return (next_token(lexer));
}

t_token	lexer_next(t_lexer *lexer)
{
	t_token	token;

	token = token_peak(lexer);
	lexer_advence(lexer, token.len);
	return (token);
}
