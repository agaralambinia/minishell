CC = cc
READLINE = rl_lib
GNL = libs/get_next_line/
SRC = 	srcs/main.c \
		srcs/prompt/prompt_msg.c \
		srcs/envp/envp_init.c \
		srcs/envp/get_envp_list_val.c \
		srcs/envp/env_set_env.c \
		srcs/envp/env_put_var.c \
		srcs/envp/env_unset_var.c \
		srcs/builtins/builtin_cd.c \
		srcs/builtins/builtin_echo.c \
		srcs/builtins/builtin_env.c \
		srcs/builtins/builtin_export.c \
		srcs/builtins/builtin_pwd.c \
		srcs/builtins/builtin_unset.c \
		srcs/builtins/builtin_exit.c \
		srcs/builtins/builtin.c \
		srcs/builtins/check_for_error.c \
		srcs/builtins/handle_redirs.c \
		srcs/builtins/handle_in_redir.c \
		srcs/builtins/handle_out_redir.c \
		srcs/builtins/print_environment_vars.c \
		srcs/error/ft_exit_error.c \
		srcs/error/ft_print_error_errno.c \
		srcs/error/ft_print_error.c \
		srcs/utils/ft_strbegins.c \
		srcs/utils/ft_maxint.c \
		srcs/utils/ft_straddchar.c \
		srcs/utils/ft_isspace.c \
		srcs/utils/ft_isspecial.c \
		srcs/utils/ft_get_env_val.c \
		srcs/utils/ft_split_count.c \
		srcs/utils/ft_arrlen.c \
		srcs/utils/check_for_exit.c \
		srcs/utils/free_arr.c \
		srcs/utils/free_cmd.c \
		srcs/utils/free_token.c \
		srcs/utils/free_mock.c \
		srcs/utils/free_redir.c \
		srcs/utils/free_envp.c \
		srcs/utils/ft_is_numeric.c \
		srcs/utils/ft_list_sort.c \
		srcs/utils/ft_list_replace.c \
		srcs/utils/ft_list_remove.c \
		srcs/utils/ft_strcmp.c \
		srcs/utils/ft_strncpy.c \
		srcs/utils/ft_lstprelast.c \
		srcs/utils/ft_atoll_p.c \
		srcs/utils/is_in_env_list.c \
		srcs/wraps/safe_malloc.c \
		srcs/parsing/lexer.c \
		srcs/parsing/word_lexer.c \
		srcs/parsing/quote_lexer.c \
		srcs/parsing/pipe_lexer.c \
		srcs/parsing/redirect_lexer.c \
		srcs/parsing/token_check.c \
		srcs/parsing/tn_clean_null.c \
		srcs/signals/ft_signals.c \
		srcs/cmd_builder/get_commands.c \
		srcs/cmd_builder/bind_field.c \
		srcs/cmd_builder/get_new_command.c \
		srcs/cmd_builder/get_word_handler.c \
		srcs/cmd_builder/add_to_word.c \
		srcs/cmd_builder/free_res.c \
		srcs/cmd_builder/handle_token.c \
		srcs/cmd_builder/add_command.c \
		srcs/execution/get_args.c \
		srcs/execution/get_pipes.c \
		srcs/execution/redir_in.c \
		srcs/execution/redir_out.c \
		srcs/execution/run.c \
		srcs/execution/run_commands.c \
		srcs/execution/run_single.c \
		srcs/execution/setup_pipes_first.c \
		srcs/execution/setup_pipes_mid.c \
		srcs/execution/setup_pipes_last.c \
		srcs/execution/setup_pipes_parent.c \
		srcs/execution/get_exit.c \
		$(GNL)get_next_line.c \
	  	$(GNL)get_next_line_utils.c

NAME = minishell
OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./libs/libft
LIBFT_NAME	= libft.a

RLDIR = libs/rl_lib

DEPS = incs/minishell.h

CFLAGS  	:= -Wall -Wextra -Werror -g
CFLAGS		+=-I incs
READLINE 	= -L $(RLDIR)/lib -lreadline


all:  ${DEPS} ${NAME}

${NAME}: ${LIBFT_PATH}/${LIBFT_NAME} $(RLDIR) ${OBJ}
	${CC} ${CFLAGS} ${LIBFT_PATH}/${LIBFT_NAME} ${SRC} ${READLINE} -o $@

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

$(RLDIR):
	bash libs/readline/rlbuild.sh

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	rm -f ${OBJ}
	cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -f ${NAME}
	rm -rf $(RLDIR)
	make fclean -C $(LIBFT_PATH)
	make distclean -C libs/readline

re: fclean all

.PHONY: all bonus clean fclean re
