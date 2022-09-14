/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_Pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:01:57 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 13:45:16 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exe_pipe(t_parse *parse, int std_i[2], int std_o[2])
{
	int	exe_pipe[2];
	int	pid_left;
	int	pid_right;

	if (pipe(exe_pipe))
		return (perror("minishll"), -1);
	pid_left = exe_simple_cmd_pid(parse->left, std_i, exe_pipe);
	if (pid_left == -1)
		return (exe_close_pipe(exe_pipe), -1);
	pid_right = exe(parse->right, exe_pipe, std_o);
	if (pid_right == -1)
		exe_close_pipe(exe_pipe);
	waitpid(pid_left, NULL, 0);
	return (pid_right);
}
