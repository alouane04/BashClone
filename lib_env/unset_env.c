/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:22:27 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:25:14 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	unset_env(char *name)
{
	t_list	*lst;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, -1);
	lst = ft_find(g_shell.envlst, name);
	if (lst)
	{
		ft_lstrm(&g_shell.envlst, lst);
		ft_lstdelone(lst, (void *)ft_free_env);
	}
	return (0);
}
