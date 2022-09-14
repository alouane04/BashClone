/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:56:28 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:33:52 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "sys/param.h"

int	exe_pwd(int ac, char **av)
{
	char	cwd[MAXPATHLEN];
	char	*pwd;

	pwd = get_env("PWD");
	if (pwd)
		ft_putstr_fd(pwd, 1);
	else if (getcwd(cwd, MAXPATHLEN))
		ft_putstr_fd(cwd, 1);
	else
		return (perror("minishell: pwd"), 1);
	return (ft_putstr_fd("\n", 1), (void)ac, (void)av, 0);
}
