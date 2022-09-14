/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:24:51 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:26:39 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	add_env(char *name, char *value)
{
	t_list	*lst;
	t_env	*env;

	env = int_env(name, value);
	lst = ft_lstnew(env);
	if (!lst || !env)
		return (ft_free_env(env), free(lst), -1);
	return (lst_put_orderly_sorted(&g_shell.envlst, lst), 0);
}
