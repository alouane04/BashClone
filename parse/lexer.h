/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:07:42 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/17 08:35:45 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../lib_env/env.h"

# define METACH " \t\n|&()<>"
# define UNQUOTED 1
# define S_QUOTED 2
# define D_QUOTED 3

typedef enum s_error
{
	L_EOF,
	L_EOT,
}	t_error;

typedef enum s_type
{
	ERROR = -1,
	EOF_T,
	PIPE,
	l_I,
	l_O,
	l_R_O,
	l_R_I,
	STR,
}	t_type;

typedef struct s_lexer
{
	char	*line;
	int		pos;
	t_error	error;
}	t_lexer;

typedef struct s_token
{
	char	*str;
	t_type	type;
	int		len;
}	t_token;

t_token	token_int(t_type type, char *str, int len);

t_token	next_token(t_lexer *lexer);

t_token	token_peak(t_lexer *lexer);

t_token	lexer_next(t_lexer *lexer);

t_lexer	lexer_int(char *line);

int		switch_mode(int mode, char c);

void	lexer_advence(t_lexer *lexer, int n);

int		enc_switch_mode(int mode, char c);

#endif