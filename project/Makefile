CC = cc
READLINE = rl_lib
GNL = libs/get_next_line/
SRC = 	srcs/main.c \
		srcs/prompt/prompt_msg.c \
		srcs/g_envp/g_envp_init.c \
		srcs/g_envp/get_envp_list_val.c \
		srcs/error/ft_exit_error.c \
		srcs/utils/ft_strbegins.c \
		srcs/utils/ft_maxint.c \
		srcs/utils/ft_straddchar.c \
		srcs/utils/ft_isspace.c \
		srcs/utils/ft_isspecial.c \
		srcs/utils/ft_get_env_val.c \
		srcs/utils/ft_arrlen.c \
		srcs/utils/check_for_exit.c \
		srcs/utils/free_arr.c \
		srcs/utils/free_cmd.c \
		srcs/wraps/safe_malloc.c \
		srcs/parsing/lexer.c \
		srcs/signals/ft_signals.c \
		srcs/cmd_builder/get_commands.c \
		srcs/cmd_builder/bind_field.c \
		srcs/cmd_builder/get_new_command.c \
		srcs/cmd_builder/get_word_handler.c \
		srcs/cmd_builder/add_to_word.c \
		srcs/cmd_builder/free_res.c \
		srcs/execution/get_args.c \
		srcs/execution/get_pipes.c \
		srcs/execution/redir_in.c \
		srcs/execution/redir_out.c \
		srcs/execution/run.c \
		srcs/execution/run_commands.c \
		srcs/execution/setup_pipes_first.c \
		srcs/execution/setup_pipes_last.c \
		srcs/execution/setup_pipes_parent.c \
		$(GNL)get_next_line.c \
	  	$(GNL)get_next_line_utils.c

NAME = minishell
OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./libs/libft
LIBFT_NAME	= libft.a

RLDIR = libs/rl_lib

DEPS = incs/minishell.h

CFLAGS  	:= -Wall -Wextra -Werror
#CFLAGS		+= -I/opt/homebrew/opt/readlineinclude
#READLINE 	= -L/opt/homebrew/opt/readline/lib -lreadline

#CFLAGS		+= -I $(RLDIR)/include/readline
CFLAGS		+=-I incs
READLINE 	= -L $(RLDIR)/lib -lreadline


all:  ${DEPS} ${NAME}
#${LIBFT_PATH}/${LIBFT_NAME}

#rlbuild 
${NAME}: ${LIBFT_PATH}/${LIBFT_NAME} ${OBJ}
	bash libs/readline/rlbuild.sh
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SRC} ${READLINE} -o $@

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

#rlbuild:

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
#	cd $(LIBFT_PATH) && make fclean


re: fclean all

.PHONY: all bonus clean fclean re
