/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:02:30 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:30:53 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exe_env(int ac, char **av)
{
	t_list	*lst;
	t_env	*env;

	if (ac > 1)
	{
		while (*++av)
		{
			if (!ft_strncmp(*av, "env", 3))
				continue ;
			return (ft_putstr_fd("env: ", 2), ft_putstr_fd(*av, 2),
				ft_putstr_fd(": No such file or directory\n", 2), 1);
		}
	}
	lst = g_shell.envlst;
	while (lst)
	{
		env = lst->content;
		if (env->value)
			printf("%s=%s\n", env->name, env->value);
		lst = lst->next;
	}
	return (0);
}
