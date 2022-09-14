/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:10:16 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/09 00:35:48 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*enc_quotes(char *line)
{
	int		mode;
	char	*s;

	mode = UNQUOTED;
	s = line;
	while (*s)
	{
		mode = switch_mode(mode, *s);
		if (*s == '"' && (mode == D_QUOTED || mode == UNQUOTED))
			*s = ENC_DQ;
		if (*s == '\'' && (mode == S_QUOTED || mode == UNQUOTED))
			*s = ENC_SQ;
		s++;
	}
	return (line);
}
