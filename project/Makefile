CC = cc

SRC = 	srcs/main.c \
		srcs/prompt.c \
		srcs/envp.c \
		srcs/error.c \
		srcs/utils/ft_strbegins.c \
		srcs/utils/ft_strdup.c \
		srcs/utils/ft_strlen.c \
		srcs/utils/ft_strchr.c \
		srcs/utils/ft_strrchr.c \
		srcs/utils/ft_bzero.c \
		srcs/utils/ft_strncmp.c \
		srcs/utils/ft_maxint.c \
		srcs/utils/get_var_value.c \
		srcs/utils/ft_straddchar.c \
		srcs/wraps/safe_malloc.c

NAME = minishell
OBJ = ${SRC:.c=.o}

DEPS = incs/minishell.h

CFLAGS  	:= -Wall -Wextra -Werror
CFLAGS		+= -I/opt/homebrew/opt/readlineinclude
READLINE 	= -L/opt/homebrew/opt/readline/lib -lreadline

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${DEPS} ${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} ${READLINE} -o $@

clean :
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
