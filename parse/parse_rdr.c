/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:46 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/28 11:45:55 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

void	free_rdr(t_rdr *rdr)
{
	if (rdr->type == R_I)
		unlink(rdr->rdr);
	free(rdr->rdr);
	free(rdr);
}

static t_rdr_type	get_rdr_type(t_token rdr)
{
	if (rdr.type == l_R_I)
		return (R_I);
	if (rdr.type == l_R_O)
		return (R_O);
	if (rdr.type == l_I)
		return (I);
	if (rdr.type == l_O)
		return (O);
	return (0);
}

t_list	*add_rdr(t_rdr_type rdr_type, t_token str, t_list **arglst)
{
	t_list	*new;
	t_rdr	*rdr;

	rdr = rdr_int(rdr_type, str);
	if (!rdr)
		return (NULL);
	new = ft_lstnew(rdr);
	if (!new)
		return (perror("minishell"), free_rdr(rdr), NULL);
	ft_lstadd_back(arglst, new);
	return (new);
}

t_list	*parse_rdr(t_lexer *lexer, t_list **rdrlst)
{
	t_token	rdr;
	t_token	str;

	rdr = token_peak(lexer);
	if (!get_rdr_type(rdr))
		return (RULE_E);
	lexer_next(lexer);
	str = lexer_next(lexer);
	if (str.type != STR)
		return (print_err(lexer), NULL);
	return (add_rdr(get_rdr_type(rdr), str, rdrlst));
}
