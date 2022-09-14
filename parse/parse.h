/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:34:05 by ariahi            #+#    #+#             */
/*   Updated: 2022/09/13 15:54:38 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <dirent.h>
# include "lexer.h"

# define ENC_DQ	-1
# define ENC_SQ -2

# define RULE_E ((void *)-1)

///////////////////////////// RDR

typedef enum e_rdr_type
{
	R_I = 1,
	R_O,
	I,
	O,
}	t_rdr_type;

typedef struct s_rdr
{
	t_rdr_type	type;
	char		*rdr;
}	t_rdr;

///////////////////////////// CMD

typedef enum e_parse_type
{
	simple_cmd,
	Pipe,
}	t_parse_type;

typedef struct s_parse
{
	t_parse_type	type;
	t_list			*rdr_lst;
	int				ac;
	char			**av;
	struct s_parse	*left;
	struct s_parse	*right;
}	t_parse;

t_parse	*parse(char *line);

t_parse	*parse_line(t_lexer *lexer);

t_parse	*parse_pipline(t_lexer *lexer);

t_parse	*parse_cmd(t_lexer *lexer);

t_parse	*parse_pipe(t_lexer *lexer);

t_parse	*ft_create_node(t_list **rdrlst, t_list **arglst);

t_parse	*parse_int(t_parse_type type, t_parse *left, t_parse *right);

t_list	*parse_cmd_elem(t_lexer *lexer, t_list **rdrlst, t_list **arglst);

t_list	*parse_glob(t_token token);

t_list	*parse_rdr(t_lexer *lexer, t_list **rdrlst);

t_list	*add_rdr(t_rdr_type rdr_type, t_token str, t_list **arglst);

t_rdr	*rdr_int(t_rdr_type rdr_type, t_token str);

///////////////////////////UTTILES

int		switch_mode(int mode, char c);

char	*expand(char *line);

char	*enc_quotes(char *line);

char	*enc_rm_quotes(char *str);

char	**lst_to_str(t_list *arglst);

void	print_err(t_lexer *lexer);

void	free_str(char **str);

void	free_node(t_parse *node);

void	free_tree_node(t_parse **parse);

void	free_rdr(t_rdr *rdr);

#endif