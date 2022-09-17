/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:54:31 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 09:07:35 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parse/parse.h"
# include "libft/libft.h"

typedef int			(*t_built_in)(int, char **);

typedef struct s_shell_s
{
	int				ac;
	char			**av;
	t_list			*envlst;
	unsigned char	exit_s;
	int				exec;
}	t_shell_s;

extern t_shell_s	g_shell;

int			int_minishell(int ac, char **av, char **env);

t_built_in	check_built_in(char **av);

int			exe_built_in(t_parse *parse, t_built_in built_in);

int			check_rdr(t_list *rdr_lst, int stdio[2]);

int			exe_execve(char *path, char **envp);

int			stdio_res(int stdio[2]);

void		exe_close_pipe(int std[2]);

int			exe_echo(int ac, char **av);

int			exe_cd(int ac, char **av);

int			exe_pwd(int ac, char **av);

int			exe_env(int ac, char **av);

int			exe_exit(int ac, char **av);

int			exe_unset(int ac, char **av);

int			exe_export(int ac, char **av);

int			exe_simple_cmd_pid(t_parse *parse, int std_i[2], int std_o[2]);

int			exe_simple_cmd(t_parse *parse, int std_i[2], int std_o[2]);

int			exe_pipe(t_parse *parse, int std_i[2], int std_o[2]);

int			exe_fork_set(int std_i[2], int std_o[2]);

int			exe_execve(char *path, char **envp);

int			exe(t_parse *parse, int std_i[2], int std_o[2]);

int			exe_waitpid(int pid);

void		exe_set_signal(int catch_signals);

#endif