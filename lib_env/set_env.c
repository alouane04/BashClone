/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:09:06 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 09:38:30 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	set_env(char *name, char *value)
{
	t_list	*lst;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, -1);
	lst = ft_find(g_shell.envlst, name);
	if (!lst)
		return (add_env(name, value));
	return (update_env(lst->content, value));
}
