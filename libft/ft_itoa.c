/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:32:17 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/27 21:32:20 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0 && ++size)
		n /= 10;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	sign = 1;
	i = count_size(n);
	if (n < 0)
	{
		i++;
		sign = -1;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--i] = (n % 10) * sign + 48;
		n /= 10;
	}
	return (str);
}
