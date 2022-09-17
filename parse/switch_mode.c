/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:26:08 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/15 16:25:27 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	switch_mode(int mode, char c)
{
	if (c == '\'')
	{
		if (mode == S_QUOTED)
			return (UNQUOTED);
		if (mode == UNQUOTED)
			return (S_QUOTED);
	}
	else if (c == '\"')
	{
		if (mode == D_QUOTED)
			return (UNQUOTED);
		if (mode == UNQUOTED)
			return (D_QUOTED);
	}
	return (mode);
}
