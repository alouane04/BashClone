/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput_orderly.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:46:13 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 15:23:13 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

t_list	*lst_put_orderly(t_list **lst, char *d_name)
{
	t_list	*new;
	char	*dup;

	dup = ft_strdup(d_name);
	new = ft_lstnew(dup);
	if (!new || !dup)
		return (free(dup), free(new), ft_lstclear(lst, free), NULL);
	return (lst_put_orderly_sorted_2(lst, new), new);
}
