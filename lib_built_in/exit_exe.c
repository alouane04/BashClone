/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:01:19 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/20 12:03:19 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

static int	is_num(char *str)
{
	errno = 0;
	if ((ft_atoll(str) == LLONG_MAX || ft_atoll(str) == LLONG_MIN) && errno)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	exe_exit(int ac, char **av)
{
	ft_putstr_fd("exit\n", 1);
	if (ac == 1)
		exit(g_shell.exit_s);
	if (ac > 2)
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
	if (!is_num(av[1]))
		return (ft_putstr_fd("minishell: exit: ", 2), ft_putstr_fd(av[1], 2),
			ft_putstr_fd(": numeric argument required\n", 2), exit(255), 255);
	exit((unsigned char)ft_atoll(av[1]));
}
