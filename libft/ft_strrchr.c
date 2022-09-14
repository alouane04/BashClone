/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:10:40 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 15:33:41 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!c)
		return ((char *)(s + ft_strlen(s)));
	i = ft_strlen(s) + 1;
	while (--i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
