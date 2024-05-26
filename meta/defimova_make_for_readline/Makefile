CC	= cc

SRC = main.c

NAME = minishell
OBJ = ${SRC:.c=.o}

CFLAGS  := -Wall -Wextra -Werror
CFLAGS	+= -I/opt/homebrew/opt/readlineinclude
READLINE = -L/opt/homebrew/opt/readline/lib -lreadline

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} ${READLINE} -o $@

clean :
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:  all bonus clean fclean re
