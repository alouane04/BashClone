/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:44:50 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 10:33:55 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

char	*get_env_n(char *name, int i)
{
	t_list	*lst;
	t_env	*env;

	if (name)
		i = ft_strnlen(name, i);
	if (!name || !i || ft_memchr(name, '=', i))
		return (errno = EINVAL, NULL);
	lst = g_shell.envlst;
	while (lst)
	{
		env = lst->content;
		if (!ft_strncmp(env->name, name, i) && env->name[i] == '\0')
			return (env->value);
		lst = lst->next;
	}
	return (NULL);
}

char	*get_env(char *name)
{
	t_list	*lst;
	t_env	*env;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, NULL);
	lst = g_shell.envlst;
	while (lst)
	{
		env = lst->content;
		if (!ft_strcmp(env->name, name))
			return (env->value);
		lst = lst->next;
	}
	return (NULL);
}
