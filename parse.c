/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:34:05 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/14 11:29:41 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "parse/lexer.h"

t_parse	*parse_line(t_lexer *lexer)
{
	t_parse	*pipline;

	pipline = parse_pipline(lexer);
	if (!pipline || pipline == RULE_E)
		return (NULL);
	return (pipline);
}

t_parse	*parse(char *line)
{
	t_parse	*parse;
	t_lexer	lexer;

	line = expand(enc_quotes(line));
	lexer = lexer_int(line);
	parse = parse_line(&lexer);
	if (!parse)
		return (parse);
	return (parse);
}
