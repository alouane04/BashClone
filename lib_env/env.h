/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:20:11 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 11:30:24 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <errno.h>

typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;

int		creat_env(char **env);

t_env	*int_env(char *name, char *value);

void	ft_free_env(t_env *env);

int		shlvl_env(void);

char	*get_env(char *name);

char	*get_env_n(char *name, int i);

char	**get_env_p(void);

int		set_env(char *name, char *value);

int		unset_env(char *name);

t_list	*ft_find(t_list *envlst, char *name);

int		add_env(char *name, char *value);

int		update_env(t_env *env, char *value);

int		cmp_env(t_env *env1, t_env *env2);

#endif