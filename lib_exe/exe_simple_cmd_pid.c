/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd_pid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:58:09 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:41:21 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exe_simple_cmd_pid(t_parse *parse, int std_i[2], int std_o[2])
{
	t_built_in	built_in;
	int			pid;

	pid = exe_fork_set(std_i, std_o);
	if (pid)
		return (pid);
	if (!parse->av && !*(parse->av))
		exit(0);
	built_in = check_built_in(parse->av);
	if (built_in)
		return (exe_built_in(parse, built_in), exit(g_shell.exit_s), 0);
	if (check_rdr(parse->rdr_lst, NULL) == -1)
		exit (1);
	exe_execve(parse->av[0], parse->av);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(parse->av[0], 2);
	if (errno == ENOENT && !ft_strchr(parse->av[0], '/'))
		ft_putstr_fd(": command not found\n", 2);
	else
		perror(NULL);
	if (errno == EACCES)
		exit(126);
	if (errno == ENOENT)
		exit(127);
	exit(1);
}
