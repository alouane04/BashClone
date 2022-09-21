/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:18:16 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/20 21:49:38 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "../minishell.h"

int	exe_waitpid(int pid)
{
	pid_t	wait;
	int		status;

	wait = waitpid(pid, &status, 0);
	if (wait == -1)
		return (wait);
	if (WIFEXITED(status))
		g_shell.exit_s = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_shell.exit_s = WTERMSIG(status);
	else
		g_shell.exit_s = 1;
	return (0);
}

int	exe_simple_cmd(t_parse *parse, int std_i[2], int std_o[2])
{
	t_built_in	built_in;
	char		**av;
	int			pid;

	built_in = check_built_in(parse->av);
	if (built_in && !std_i && !std_o)
		return (exe_built_in(parse, built_in));
	pid = exe_simple_cmd_pid(parse, std_i, std_o);
	av = parse->av;
	if (pid == -1)
		return (-1);
	if (av && av[0] && !ft_strcmp(g_shell.av[0], av[0]))
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (exe_waitpid(pid))
		return (-1);
	return (exe_set_signal(0), 0);
}
