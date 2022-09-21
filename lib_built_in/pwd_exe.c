/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:07:53 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/20 12:08:25 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "sys/param.h"

int	exe_pwd(int ac, char **av)
{
	char	cwd[MAXPATHLEN];

	if (getcwd(cwd, MAXPATHLEN))
		ft_putstr_fd(cwd, 1);
	else
		return (perror("minishell: pwd"), 1);
	return (ft_putstr_fd("\n", 1), (void)ac, (void)av, 0);
}
