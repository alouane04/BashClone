/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:23:58 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:26:23 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

static int	len_env(t_list *lst)
{
	t_env	*env;
	int		i;

	i = 1;
	while (lst)
	{
		env = lst->content;
		if (env->value)
			i++;
		lst = lst->next;
	}
	return (i);
}

static char	*allocat_env(t_env *env)
{
	char	*str;
	char	*s;

	s = ft_strjoin(env->name, "=");
	if (!s)
		return (NULL);
	str = ft_strjoin(s, env->value);
	if (!str)
		return (free(s), NULL);
	return (str);
}

char	**get_env_p(void)
{
	char	**env_p;
	t_list	*lst;
	t_env	*env;
	int		i;

	i = 0;
	lst = g_shell.envlst;
	env_p = malloc(sizeof(char *) * len_env(lst));
	if (!env_p)
		return (NULL);
	while (lst)
	{
		env = lst->content;
		if (env->value)
		{
			env_p[i] = allocat_env(env);
			if (!env_p[i])
				break ;
			i++;
		}
		lst = lst->next;
	}
	if (!env_p)
		return (free_str(env_p), NULL);
	return (env_p[i] = NULL, env_p);
}
