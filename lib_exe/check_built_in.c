/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:31:19 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:41:09 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_built_in	check_built_in(char **av)
{
	if (!av || !av[0])
		return (NULL);
	if (!ft_strcmp(av[0], "echo"))
		return (exe_echo);
	if (!ft_strcmp(av[0], "cd"))
		return (exe_cd);
	if (!ft_strcmp(av[0], "pwd"))
		return (exe_pwd);
	if (!ft_strcmp(av[0], "export"))
		return (exe_export);
	if (!ft_strcmp(av[0], "unset"))
		return (exe_unset);
	if (!ft_strcmp(av[0], "env"))
		return (exe_env);
	if (!ft_strcmp(av[0], "exit"))
		return (exe_exit);
	return (NULL);
}
