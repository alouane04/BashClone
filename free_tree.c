/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:15:32 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/14 09:38:04 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lstclear_p(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free_rdr((*lst)->content);
		free((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}

void	free_tree(t_parse **parse)
{
	t_parse	*tree;

	tree = *parse;
	if (!tree)
		return ;
	free_tree_node(&tree->left);
	free_tree_node(&tree->right);
	if (!*parse)
		return ;
	free_str((*parse)->av);
	lstclear_p(&(*parse)->rdr_lst);
	free(*parse);
}
