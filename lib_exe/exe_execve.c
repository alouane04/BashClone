/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 04:27:12 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:22:37 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

static int	exe_exec(char *path, char **envp)
{
	char	**env_p;

	env_p = get_env_p();
	if (!env_p)
		return (-1);
	execve(path, envp, env_p);
	free_str(env_p);
	return (-1);
}

static char	*join_path(char *path, char *dir, char *file)
{
	if (*dir == '\0')
		dir = ".";
	path[0] = '\0';
	if (ft_strlcat(path, dir, PATH_MAX) >= PATH_MAX
		|| ft_strlcat(path, "/", PATH_MAX) >= PATH_MAX
		|| ft_strlcat(path, file, PATH_MAX) >= PATH_MAX)
		return (errno = ENAMETOOLONG, NULL);
	return (path);
}

static int	exe_path(char *path, char *path_env, char **envp)
{
	char	exe_path[PATH_MAX];
	char	*dup;
	char	*str;
	int		acces;

	acces = 1;
	dup = ft_strdup(path_env);
	if (!dup)
		return (-1);
	str = dup;
	while (str)
	{
		if (join_path(exe_path, ft_strsep(&str, ":"), path) == NULL)
			break ;
		exe_exec(exe_path, envp);
		if (errno == EACCES)
			acces = 0;
		else if (errno == ENOENT || errno == ENOTDIR)
			continue ;
		break ;
	}
	if (!acces)
		errno = EACCES;
	return (free(dup), -1);
}

int	exe_execve(char *path, char **envp)
{
	char	*path_env;

	errno = ENOENT;
	if (!*path)
		return (-1);
	if (ft_strchr(path, '/'))
		return (exe_exec(path, envp));
	path_env = get_env("PATH");
	if (!path_env)
		return (-1);
	return (exe_path(path, path_env, envp));
}
