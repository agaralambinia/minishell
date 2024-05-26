NAME = minishell
READLINE = rl_lib
SRC = main.c
OBJ = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) -lreadline
#	cc -o $(NAME) $(OBJ) -L $(READLINE)/lib -lreadline 
#	cc -o $(NAME) $(OBJ) readline/libreadline.a readline/libhistory.a ncurses-6.5/lib/libncursesw.a #-lhistory 

%.o: %.c
	cc  $(CFLAGS) -c $< -o $@
#	cc -I $(READLINE)/include/readline $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)
