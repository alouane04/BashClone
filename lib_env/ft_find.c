/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:19:18 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/09 15:05:42 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list	*ft_find(t_list *envlst, char *name)
{
	t_env	*env;

	while (envlst)
	{
		env = envlst->content;
		if (!ft_strcmp(env->name, name))
			return (envlst);
		envlst = envlst->next;
	}
	return (NULL);
}
