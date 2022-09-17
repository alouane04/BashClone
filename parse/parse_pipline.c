/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:47:40 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 19:37:55 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "../minishell.h"

void	print_err(t_lexer *lexer, t_token token)
{
	if (token.type == EOF_T)
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
	else if (token.type == ERROR)
	{
		if ((*lexer).error == L_EOF)
			ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		else if ((*lexer).error == L_EOT)
		{
			ft_putstr_fd("minishell: syntax error: ", 2);
			ft_putstr_fd("unrecognized token at position ", 2);
			ft_putnbr_fd((*lexer).pos + 1, 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
		write(2, token.str, token.len);
		ft_putstr_fd("'\n", 2);
	}
}

t_parse	*parse_pipe(t_lexer *lexer)
{
	t_parse	*pipline;
	t_parse	*pipe;

	if (token_peak(lexer).type != PIPE)
		return (RULE_E);
	lexer_next(lexer);
	pipline = parse_pipline(lexer);
	if (pipline == RULE_E)
		return (print_err(lexer, token_peak(lexer)), NULL);
	pipe = parse_int(Pipe, NULL, pipline);
	if (!pipe && !pipline)
		return (free_tree(&pipe), free_tree(&pipline), NULL);
	return (pipe);
}

t_parse	*parse_pipline(t_lexer *lexer)
{
	t_parse	*cmd;
	t_parse	*pipe;

	cmd = parse_cmd(lexer);
	if (cmd && cmd != RULE_E)
	{
		pipe = parse_pipe(lexer);
		if (pipe == RULE_E)
			return (cmd);
		if (pipe)
			pipe->left = cmd;
		else
			free_tree(&cmd);
		return (pipe);
	}
	return (cmd);
}
