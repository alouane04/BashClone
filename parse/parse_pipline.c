/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:47:40 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/15 08:30:39 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

void	free_tree_node(t_parse **parse)
{
	t_parse	*tree;

	tree = *parse;
	if (!tree)
		return ;
	free_tree_node(&tree->left);
	free_tree_node(&tree->right);
	free_node(tree);
	*parse = NULL;
}

void	print_err(t_lexer *lexer)
{
	ft_putstr_fd("errur on line: ", 2);
	ft_putstr_fd(lexer->line, 2);
	ft_putstr_fd("'\n'in token: ", 2);
	ft_putstr_fd(token_peak(lexer).str, 2);
	ft_putstr_fd("'\n'in position ", 2);
	ft_putstr_fd(ft_itoa(lexer->pos), 2);
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
		return (print_err(lexer), NULL);
	pipe = parse_int(Pipe, NULL, pipline);
	if (!pipe && !pipline)
		return (free_tree_node(&pipe), free_tree_node(&pipline), pipe);
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
			free_tree_node(&cmd);
		return (pipe);
	}
	return (cmd);
}
