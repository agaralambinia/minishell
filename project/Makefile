CC = cc

SRC = 	srcs/main.c \
		srcs/prompt/prompt_msg.c \
		srcs/envp/envp_init.c \
		srcs/envp/get_var_value.c \
		srcs/error/ft_exit_error.c \
		srcs/utils/ft_strbegins.c \
		srcs/utils/ft_maxint.c \
		srcs/utils/ft_straddchar.c \
		srcs/wraps/safe_malloc.c

NAME = minishell
OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./libs/libft
LIBFT_NAME	= libft.a

DEPS = incs/minishell.h

CFLAGS  	:= -Wall -Wextra -Werror
READLINE 	= -L/opt/homebrew/opt/readline/lib -lreadline
CFLAGS		+= -I/opt/homebrew/opt/readlineinclude

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${LIBFT_PATH}/${LIBFT_NAME} ${DEPS} ${NAME}

${NAME}: ${LIBFT_PATH}/${LIBFT_NAME} ${OBJ}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SRC} ${READLINE} -o $@

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

clean :
	rm -f ${OBJ}
	cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -f ${NAME}
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all bonus clean fclean re
