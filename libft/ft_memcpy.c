/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:01:27 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 12:21:34 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c_dst;
	char	*c_src;

	i = -1;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!src && !dst)
		return (NULL);
	while (++i < n)
		c_dst[i] = c_src[i];
	return (dst);
}
