/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:55:36 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/02 22:56:00 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **str, const char *sep)
{
	char	*s;
	char	*end;

	s = *str;
	if (!s)
		return (NULL);
	end = s + ft_strcspn(s, sep);
	if (*end)
		*end++ = '\0';
	else
		end = NULL;
	*str = end;
	return (s);
}
