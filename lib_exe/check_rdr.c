/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:51:27 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 19:38:08 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

static	int	open_file(t_rdr *rdr)
{
	int	fd;

	fd = -1;
	if (rdr->type == I || rdr->type == R_I)
		fd = open(rdr->rdr, O_RDONLY);
	else if (rdr->type == R_O)
		fd = open(rdr->rdr, O_WRONLY | O_APPEND | O_CREAT, 0664);
	else if (rdr->type == O)
		fd = open(rdr->rdr, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd == -1)
		return (ft_putstr_fd("minishell:", 2), ft_putstr_fd(rdr->rdr, 2),
			ft_putstr_fd(":", 2), perror(NULL), -1);
	return (fd);
}

int	stdio_res(int stdio[2])
{
	if (!stdio)
		return (0);
	if (dup2(stdio[0], 0) == -1 || dup2(stdio[1], 1) == -1)
		return (perror("minishell"), -1);
	return (0);
}

static	int	stdio_dup(int stdio[2])
{
	if (!stdio)
		return (0);
	stdio[0] = dup(0);
	if (stdio[0] == -1)
		return (perror("minishell"), -1);
	stdio[1] = dup(1);
	if (stdio[1] == -1)
		return (perror("minishell"), -1);
	return (0);
}

static	int	stdio_dup2(t_rdr *rdr, int fd)
{
	int	fd_dup2;

	fd_dup2 = -1;
	if (rdr->type == R_I || rdr->type == I)
		fd_dup2 = dup2(fd, 0);
	else
		fd_dup2 = dup2(fd, 1);
	if (fd_dup2 == -1)
		perror("minishell");
	return (fd_dup2);
}

int	check_rdr(t_list *rdr_lst, int stdio[2])
{
	int	fd[2];

	if (stdio_dup(stdio))
		return (-1);
	while (rdr_lst)
	{
		fd[0] = open_file(rdr_lst->content);
		fd[1] = stdio_dup2(rdr_lst->content, fd[0]);
		if (fd[0] == -1 || fd[1] == -1)
			return (close(fd[0]), stdio_res(stdio), -1);
		close(fd[0]);
		rdr_lst = rdr_lst->next;
	}
	return (0);
}
