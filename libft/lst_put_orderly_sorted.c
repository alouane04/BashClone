/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_put_orderly_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:22:06 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 11:16:02 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_put_orderly_sorted(t_list **lst, t_list *new, t_cmpfn cmpfn)
{
	t_list	*cur;
	t_list	*pre;

	cur = *lst;
	if (!cur || cmpfn(cur->content, new->content) > 0)
		ft_lstadd_front(lst, new);
	else
	{
		pre = cur;
		cur = cur->next;
		while (cur && cmpfn(cur->content, new->content) <= 0)
		{
			pre = cur;
			cur = cur->next;
		}
		new->next = cur;
		pre->next = new;
	}
}
