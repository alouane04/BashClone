/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:14:01 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:08:24 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			nb;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		nb = (str[i++] - 48);
		if (sign == 1 && (res - LLONG_MAX) / 10 < res)
			return (errno = ERANGE, LLONG_MAX);
		if (sign == -1 && (res + LLONG_MIN) / 10 > res)
			return (errno = ERANGE, LLONG_MIN);
		res = res * 10 + nb * sign;
	}
	return (res);
}
