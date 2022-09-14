/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:32:48 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 15:55:17 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**lst_to_str(t_list *arglst)
{
	char	**av;
	int		i;

	av = malloc(sizeof(char *) * (ft_lstsize(arglst) + 1));
	if (!av)
		return (av);
	i = 0;
	while (arglst)
	{
		av[i] = ft_strdup(arglst->content);
		if (!av[i++])
			return (free_str(av), NULL);
		arglst = arglst->next;
	}
	return (av[i] = NULL, av);
}

void	free_node(t_parse *parse)
{
	if (!parse)
		return ;
	free_str(parse->av);
	ft_lstclear(&parse->rdr_lst);
	free(parse);
}

t_parse	*parse_int(t_parse_type type, t_parse *left, t_parse *right)
{
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (parse);
	parse->left = left;
	parse->right = right;
	parse->type = type;
	return (parse);
}

t_parse	*ft_create_node(t_list **rdrlst, t_list **arglst)
{
	t_parse	*node;
	char	**av;
	int		ac;

	node = parse_int(simple_cmd, NULL, NULL);
	av = lst_to_str(*arglst);
	ac = ft_lstsize(*arglst);
	ft_lstclear(arglst);
	if (!av || !node)
		return (perror("minishell"), free_node(node),
			free_str(av), ft_lstclear(rdrlst), NULL);
	node->rdr_lst = *rdrlst;
	node->av = av;
	node->ac = ac;
	return (node);
}
