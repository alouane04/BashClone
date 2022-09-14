/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:28:34 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:33:22 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_export(void)
{
	t_list	*lst;
	t_env	*env;

	lst = g_shell.envlst;
	while (lst)
	{
		env = lst->content;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->name, 1);
		if (env->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

static int	export(char *av)
{
	char	*name;
	int		i;

	i = 1;
	name = ft_strsep(&av, "=");
	if (!ft_isalpha(*name) && *name != '_')
		return (ft_putstr_fd("minishell: export: '", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd("=", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier\n", 2), 1);
	while (ft_isalnum(name[i]) || name[i] == '_')
		i++;
	if (name[i] != '\0')
		return (ft_putstr_fd("minishell: export: '", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd("=", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier\n", 2), 1);
	if (set_env(name, av))
		return (ft_putstr_fd("minishell: export: '", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd("=", 2), ft_putstr_fd(av, 2), perror("': "), 1);
	return (0);
}

int	exe_export(int ac, char **av)
{
	int	exit_s;

	exit_s = 0;
	if (ac == 1)
		return (print_export(), 0);
	av++;
	while (*av)
		if (export(*av++))
			exit_s = 1;
	return (exit_s);
}
