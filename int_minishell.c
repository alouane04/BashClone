/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:31:09 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 14:02:53 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_env/env.h"

t_shell_s	g_shell;

int	creat_env(char **env)
{
	char	*name;
	t_env	*t_env;
	t_list	*lst;

	while (*env)
	{
		name = ft_strsep(&*env, "=");
		t_env = int_env(name, *env);
		lst = ft_lstnew(t_env);
		if (!t_env || !lst)
			return (ft_free_env(t_env), free(lst), -1);
		lst_put_orderly_sorted(&g_shell.envlst, lst, (t_cmpfn)cmp_env);
		env++;
	}
	return (0);
}

int	shlvl_env(void)
{
	char	*value;

	value = get_env("SHLVL");
	if (value)
	{
		value = ft_itoa(ft_atoi(value) + 1);
		if (!value || set_env("SHLVL", value))
			return (free(value), -1);
		free(value);
	}
	else
		if (set_env("SHLVL", "1"))
			return (-1);
	return (0);
}

int	int_minishell(int ac, char **av, char **env)
{
	g_shell.ac = ac;
	g_shell.av = av;
	g_shell.exec = 0;
	g_shell.exit_s = 0;
	g_shell.envlst = NULL;
	if (creat_env(env) || shlvl_env() || set_env("SHELL", av[0]))
		return (perror("minishell"),
			ft_lstclear(&g_shell.envlst, (t_delfn)ft_free_env), -1);
	return (0);
}
