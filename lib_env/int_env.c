/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:23:11 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/16 14:40:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*int_env(char *name, char *value)
{
	t_env	*env;
	char	*name_d;
	char	*value_d;

	env = malloc(sizeof(t_env));
	name_d = ft_strdup(name);
	value_d = NULL;
	if (value)
		value_d = ft_strdup(value);
	if (!env || !name || (value && !value_d))
		return (free(env), free(name_d), free(value_d), NULL);
	return (env->name = name_d, env->value = value_d, env);
}
