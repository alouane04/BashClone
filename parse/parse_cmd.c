/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:09:44 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 10:56:23 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

t_list	*parse_cmd_elem(t_lexer *lexer, t_list **rdrlst, t_list **arglst)
{
	t_list	*lst;

	if (token_peak(lexer).type == STR)
	{
		lst = parse_glob(lexer_next(lexer));
		if (lst)
			ft_lstadd_back(arglst, lst);
		return (lst);
	}
	else
		return (parse_rdr(lexer, rdrlst));
}

t_parse	*parse_cmd(t_lexer *lexer)
{
	t_list	*cmd_e;
	t_list	*rdrlst;
	t_list	*arglst;

	rdrlst = NULL;
	arglst = NULL;
	cmd_e = parse_cmd_elem(lexer, &rdrlst, &arglst);
	while (cmd_e && cmd_e != RULE_E)
		cmd_e = parse_cmd_elem(lexer, &rdrlst, &arglst);
	if (!cmd_e)
		return (ft_lstclear(&rdrlst), ft_lstclear(&arglst), NULL);
	if (!rdrlst && !arglst)
		return (RULE_E);
	return (ft_create_node(&rdrlst, &arglst));
}
