/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_fork_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:15:38 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 12:14:28 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_close_pipe(int std[2])
{
	if (!std)
		return ;
	close(std[0]);
	close(std[1]);
}

static void	exe_fork_pipes_set(int std_i[2], int std_o[2])
{
	if (std_i && dup2(std_i[0], 0) == -1)
	{
		perror("minishell");
		exit(1);
	}
	exe_close_pipe(std_i);
	if (std_o && dup2(std_o[1], 1) == -1)
	{
		perror("minishell");
		exit(1);
	}
	exe_close_pipe(std_o);
}

int	exe_fork_set(int std_i[2], int std_o[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)
		exe_fork_pipes_set(std_i, std_o);
	else if (pid == -1)
		perror("minishell");
	else
		exe_close_pipe(std_i);
	return (pid);
}
