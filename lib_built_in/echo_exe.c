/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:07:26 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/22 12:53:11 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_option(char *av)
{
	if (*av != '-' || *++av != 'n')
		return (0);
	av++;
	while (*av == 'n')
		av++;
	if (*av == '\0')
		return (1);
	return (0);
}

int	exe_echo(int ac, char **av)
{
	int	i;

	(void)ac;
	av++;
	i = 1;
	while (*av)
	{
		if (!check_option(*av))
			break ;
		i = 0;
		av++;
	}
	while (*av)
	{
		ft_putstr_fd(*av, 1);
		av++;
		if (*av)
			ft_putstr_fd(" ", 1);
	}
	if (i)
		ft_putstr_fd("\n", 1);
	return (0);
}
