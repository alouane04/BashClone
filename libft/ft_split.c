/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 06:27:52 by ariahi            #+#    #+#             */
/*   Updated: 2021/11/28 10:41:02 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static int	count_s(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = count_w(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static char	*put_str(char const *s, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	while (len--)
		str[len] = s[len];
	return (str);
}

char	**ft_split(char	const *s, char c)
{
	char	**s_t;
	int		s_c;
	int		w_c;
	int		i;

	i = -1;
	if (!s)
		return (0);
	s_c = count_s(s, c);
	s_t = (char **)malloc(sizeof(char *) * (s_c + 1));
	if (!s_t)
		return (0);
	while (++i < s_c)
	{
		while (*s && *s == c)
			s++;
		w_c = count_w(s, c);
		s_t[i] = put_str(s, w_c);
		if (!(s_t[i]))
			return (ft_free(s_t), NULL);
		s += w_c;
	}
	s_t[s_c] = 0;
	return (s_t);
}
