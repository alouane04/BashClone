/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:46:23 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 11:12:58 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parse/parse.h"

int	exe(t_parse *parse, int std_i[2], int std_o[2])
{
	if (parse->type == simple_cmd)
		return (exe_simple_cmd(parse, std_i, std_o));
	if (parse->type == Pipe)
		return (exe_pipe(parse, std_i, std_o));
	return (-1);
}
