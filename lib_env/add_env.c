/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:24:51 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 11:33:28 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int cmp_env(t_env *env1, t_env *env2)
{
	int	cmp;

	cmp = ft_strcmp(env1->name, env2->name);
	return (cmp);
}

int	add_env(char *name, char *value)
{
	t_list	*lst;
	t_env	*env;

	env = int_env(name, value);
	lst = ft_lstnew(env);
	if (!lst || !env)
		return (ft_free_env(env), ft_lstdelone(lst, NULL), -1);
	return (lst_put_orderly_sorted(&g_shell.envlst, lst, (t_cmpfn)cmp_env), 0);
}
