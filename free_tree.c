/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:15:32 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 18:41:29 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse/parse.h"

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_tree_node(t_parse *parse)
{
	if (!parse)
		return ;
	free_str(parse->av);
	ft_lstclear(&parse->rdr_lst, (t_delfn)free_rdr);
	free(parse);
}

void	free_tree(t_parse **parse)
{
	t_parse	*tree;

	tree = *parse;
	if (!tree)
		return ;
	free_tree(&tree->left);
	free_tree(&tree->right);
	free_tree_node(tree);
	*parse = NULL;
}
