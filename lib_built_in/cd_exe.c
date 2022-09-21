/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:44:24 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/20 12:01:49 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/param.h>

static	int	home(void)
{
	if (!get_env("HOME"))
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), -1);
	return (0);
}

int	exe_cd(int ac, char **av)
{
	char	old_pwd[MAXPATHLEN];
	char	new_pwd[MAXPATHLEN];
	char	*dst;

	if (ac == 1 && home())
		return (1);
	if (ac == 1)
		dst = get_env("HOME");
	else
		dst = av[1];
	old_pwd[0] = '\0';
	getcwd(old_pwd, MAXPATHLEN);
	if (chdir(dst))
		return (ft_putstr_fd("minishell: cd: ", 2), ft_putstr_fd(dst, 2),
			perror(" "), 1);
	if (!getcwd(new_pwd, MAXPATHLEN))
		return (ft_putstr_fd("minishell: cd: ", 2),
			ft_putstr_fd("error retieving current directory: ", 2),
			ft_putstr_fd("getcwd: cannot access parent directories: ", 2),
			perror(NULL), 1);
	if (!ft_strlen(old_pwd) && get_env("PWD"))
		ft_strlcpy(old_pwd, get_env("PWD"), MAXPATHLEN);
	if (set_env("OLDPWD", old_pwd) || set_env("PWD", new_pwd))
		return (ft_putstr_fd("minishell: cd: ", 2), perror(NULL), 1);
	return (0);
}
