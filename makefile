# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:09:16 by ariahi            #+#    #+#              #
#    Updated: 2022/09/20 16:18:02 by rel-maza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c int_minishell.c expand.c parse.c free_tree.c\
	lib_exe/check_built_in.c lib_exe/check_rdr.c lib_exe/exe.c\
		lib_exe/exe_pipe.c lib_exe/exe_built_in.c lib_exe/exe_execve.c\
			lib_exe/exe_fork_set.c lib_exe/exe_signals.c lib_exe/exe_simple_cmd.c\
				lib_exe/exe_simple_cmd_pid.c\
	parse/enc_quotes.c parse/enc_rm_quotes.c parse/enc_switch_mode.c\
		parse/ft_create_node.c parse/lexer.c parse/next_token.c parse/parse_glob.c\
			parse/parse_pipline.c parse/parse_rdr.c parse/rdr_int.c\
				parse/switch_mode.c parse/parse_cmd.c\
	lib_env/add_env.c lib_env/ft_free_env.c lib_env/get_env.c lib_env/int_env.c\
		lib_env/set_env.c lib_env/update_env.c lib_env/ft_find.c\
			lib_env/get_env_p.c lib_env/unset_env.c\
	lib_built_in/cd_exe.c lib_built_in/echo_exe.c lib_built_in/env_exe.c\
		lib_built_in/exit_exe.c lib_built_in/export_exe.c lib_built_in/pwd_exe.c\
			lib_built_in/unset_exe.c\

NAME = minishell

CC = cc

CFLAGS = -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/rel-maza/.brew/opt/readline/include -Wall -Wextra -Werror -MMD -g

DEP = $(SRC:.c=.d)

$(NAME): $(SRC) libft/libft.a
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a -lreadline

.PHONY: all re clean fclean bonus

libft/libft.a:
	make -C Libft all

all: $(NAME)

clean:
	make -C Libft clean
	rm -rf $(DEP)

fclean:
	make -C Libft fclean
	rm -rf $(NAME) $(DEP)

re: fclean all
-include $(DEP)
