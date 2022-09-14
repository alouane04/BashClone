/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:57:39 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 18:25:55 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = (char *)malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	else
	{
		ft_memcpy(s, s1, len1);
		ft_memcpy(s + len1, s2, len2 + 1);
	}
	return (s);
}
