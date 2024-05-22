NAME = minishell
READLINE = readline-8.2/
SRC = main.c
OBF = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ)
	ls $(READLINE) | grep '.o$$' | sed 's:^:$(READLINE):' | xargs cc $(OBJ) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
