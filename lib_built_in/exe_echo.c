/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:42:21 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:31:23 by ariahi           ###   ########.fr       */
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
