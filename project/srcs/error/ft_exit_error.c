#include "../../incs/minishell.h"

void	ft_exit_error(char *error)
{
	printf(RED"%s\n"RESET, error);
	exit(EXIT_FAILURE);
}