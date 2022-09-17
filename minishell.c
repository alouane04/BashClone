/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:41:44 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 22:30:19 by ariahi           ###   ########.fr       */
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

	// TO USE LEAKS CMD REFFRESHED EVERY 0.5S WHILE DEBUGING
	
	//while true; do leaks minishell10; sleep 0.5; clear; done
	
	// TO USE VALGRIND TO DETECT WHERE THE LEAKS COME FROOM

	//valgrind --leak-check=full ./minishell10
	
	// FOR TEST PURPASE WITH LLDB IN VSCODE
	
	// line = strdup("pwd >> l.txt");
	// if (ft_strspn(line, " \t\n") < ft_strlen(line))
	// 	add_history(line);
	// p = parse(line);
	// if (p)
	// {
	// 	g_shell.exec = 1;
	// 	if (exe(p, NULL, NULL))
	// 		g_shell.exit_s = 1;
	// 	g_shell.exec = 0;
	// }
	// free_tree(&p);
	// free(line);

	ft_putstr_fd("exit\n", 1);
	ft_free_int_minishell(&g_shell.envlst);
	
	// FOR CMD LEAK
	//while (1);
	return (g_shell.exit_s);
}
