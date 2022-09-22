/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_put_orderly_sorted_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:22:06 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 15:20:24 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_put_orderly_sorted_2(t_list **lst, t_list *new)
{
	t_list	*cur;
	t_list	*pre;

	cur = *lst;
	if (!cur || ft_strcmp(cur->content, new->content) > 0)
		ft_lstadd_front(lst, new);
	else
	{
		pre = cur;
		cur = cur->next;
		while (cur && ft_strcmp(cur->content, new->content) <= 0)
		{
			pre = cur;
			cur = cur->next;
		}
		new->next = cur;
		pre->next = new;
	}
}
