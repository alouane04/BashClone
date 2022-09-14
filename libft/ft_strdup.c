/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:29:35 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/16 13:05:50 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;

	len = ft_strlen(s1) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_memmove(s, s1, len));
}
