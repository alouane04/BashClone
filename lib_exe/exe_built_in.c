/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_built_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:46:21 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/20 21:53:17 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "../minishell.h"

int	exe_built_in(t_parse *parse, t_built_in built_in)
{
	int	stdio[2];
	int	i;

	i = check_rdr(parse->rdr_lst, stdio);
	if (i)
		return (-1);
	g_shell.exit_s = built_in(parse->ac, parse->av);
	i = stdio_res(stdio);
	if (i)
		return (-1);
	return (0);
}
