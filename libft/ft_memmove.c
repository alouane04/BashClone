/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:49:56 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 14:30:59 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (c_dst > c_src)
	{
		while (len--)
			c_dst[len] = c_src[len];
		return (dst);
	}
	while (len--)
		*c_dst++ = *c_src++;
	return (dst);
}
