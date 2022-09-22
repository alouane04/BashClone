/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:19:53 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/22 14:20:00 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sig_int_handler(int sig)
{
	rl_replace_line("", 0);
	ft_putstr_fd("\n", 1);
	if (g_shell.exec)
		return ;
	rl_on_new_line();
	rl_redisplay();
	g_shell.exit_s = 128 + sig;
}

static void	sig_quit_handler(int sig)
{
	if (!g_shell.exec)
		return ;
	rl_replace_line("", 0);
	ft_putstr_fd("Quit: ", 1);
	ft_putnbr_fd(sig, 1);
	ft_putstr_fd("\n", 1);
}

void	exe_set_signal(int catch_signals)
{
	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, sig_quit_handler);
	if (catch_signals)
		rl_catch_signals = 0;
}

int	event(void)
{
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_shell.exec = -1;
		rl_done = 1;
	}
}
