/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:15:26 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 22:01:32 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, t_delfn fn)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, fn);
	}
}
