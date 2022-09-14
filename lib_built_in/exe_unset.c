/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:46:57 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:32:44 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	unset(char *av)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*av) && *av != '_')
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier\n", 2), 1);
	while (ft_isalnum(av[i]) || av[i] == '_')
		i++;
	if (av[i] != '\0')
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier", 2), 1);
	if (unset_env(av))
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			perror("': "), 1);
	return (0);
}

int	exe_unset(int ac, char **av)
{
	int	exit_s;

	exit_s = 0;
	av++;
	while (*av)
		if (unset(*av++))
			exit_s = 0;
	return ((void)ac, exit_s);
}
