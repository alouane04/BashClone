/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_switch_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:26:08 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/22 13:01:04 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	enc_switch_mode(int mode, char c)
{
	if (c == ENC_SQ)
	{
		if (mode == S_QUOTED)
			return (UNQUOTED);
		if (mode == UNQUOTED)
			return (S_QUOTED);
	}
	else if (c == ENC_DQ)
	{
		if (mode == D_QUOTED)
			return (UNQUOTED);
		if (mode == UNQUOTED)
			return (D_QUOTED);
	}
	return (mode);
}
