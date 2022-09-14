/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:59:10 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:25:23 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	update_env(t_env *env, char *value)
{
	char	*value_d;

	if (env->value && !value)
		return (0);
	value_d = NULL;
	if (value)
	{
		value_d = ft_strdup(value);
		if (!value_d)
			return (-1);
	}
	return (free(env->value), env->value = value_d, 0);
}
