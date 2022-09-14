/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_rm_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:40:05 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/24 01:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*enc_rm_quotes(char *str)
{
	char	*s;
	int		n;

	s = str;
	n = ft_strlen(s) + 1;
	while (*s)
	{
		if (*s == ENC_SQ || *s == ENC_DQ)
			ft_memcpy(s, s + 1, n - 1);
		else
			s++;
		n--;
	}
	return (str);
}
