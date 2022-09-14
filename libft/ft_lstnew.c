/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:08:58 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 23:34:50 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_e;

	new_e = (t_list *)malloc(sizeof(t_list));
	if (!new_e)
		return (NULL);
	new_e->content = content;
	new_e->next = NULL;
	return (new_e);
}
