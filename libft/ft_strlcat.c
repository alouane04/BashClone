/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:58:30 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/15 17:23:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i == dstsize || dstsize < 0)
		return (i + ft_strlen(src));
	while (src[j] && j < (dstsize - i - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
