CC = cc

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
		srcs/wraps/safe_malloc.c \
		srcs/parsing/lexer.c \
		srcs/piping/piping.c

NAME = minishell
OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./libs/libft
LIBFT_NAME	= libft.a

RLDIR = libs/rl_lib

DEPS = incs/minishell.h

CFLAGS  	:= -Wall -Wextra -Werror
#CFLAGS		+= -I/opt/homebrew/opt/readlineinclude
#READLINE 	= -L/opt/homebrew/opt/readline/lib -lreadline

CFLAGS		+= -I incs
CFLAGS		+= -I $(RLDIR)/include/readline
READLINE 	= -L $(RLDIR)/lib -lreadline

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${LIBFT_PATH}/${LIBFT_NAME} ${DEPS} ${NAME}

${NAME}: ${LIBFT_PATH}/${LIBFT_NAME} ${OBJ}
	bash libs/readline/rlbuild.sh
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SRC} ${READLINE} -o $@

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

clean :
	rm -f ${OBJ}
	cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -f ${NAME}
	rm -rf $(RLDIR)
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all bonus clean fclean re
