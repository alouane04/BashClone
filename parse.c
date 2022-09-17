/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:34:05 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 19:39:35 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "parse/lexer.h"

t_parse	*parse_line(t_lexer *lexer)
{
	t_token	token;
	t_parse	*pipline;

	pipline = parse_pipline(lexer);
	if (!pipline || pipline == RULE_E)
		return (pipline);
	token = lexer_next(lexer);
	if (token.type != EOF_T)
		return (print_err(lexer, token), free_tree(&pipline), pipline);
	return (pipline);
}

t_parse	*parse(char *line)
{
	t_parse	*parse;
	t_lexer	lexer;

	line = expand(enc_quotes(line));
	lexer = lexer_int(line);
	parse = parse_line(&lexer);
	free(line);
	if (!parse || parse == RULE_E)
		return (NULL);
	return (parse);
}
