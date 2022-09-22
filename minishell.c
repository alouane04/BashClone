/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:41:44 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 13:56:07 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse/parse.h"

static void	ft_free_int_minishell(t_list **envlst)
{
	t_list	*tmp;

	while (*envlst)
	{
		tmp = (*envlst)->next;
		ft_free_env((*envlst)->content);
		free(*envlst);
		*envlst = tmp;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_parse	*p;

	if (int_minishell(ac, av, env))
		return (1);
	exe_set_signal(1);
	line = readline("minishell> ");
	while (line)
	{
		if (ft_strspn(line, " \t\n") < ft_strlen(line))
			add_history(line);
		p = parse(line);
		if (p)
		{
			g_shell.exec = 1;
			if (exe(p, NULL, NULL))
				g_shell.exit_s = 1;
			g_shell.exec = 0;
		}
		free_tree(&p);
		free(line);
		line = readline("minishell> ");
	}
	ft_putstr_fd("exit\n", 1);
	return (ft_free_int_minishell(&g_shell.envlst), g_shell.exit_s);
}
