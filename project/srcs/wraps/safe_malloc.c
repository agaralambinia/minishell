#include "../../incs/minishell.h"

void	*safe_malloc(size_t str)
{
	void	*result;

	result = malloc(str);
	if (result == NULL)
		ft_exit_error("Error with the malloc"); //TODO вместо ft_exit_error ft_exit_shell
	ft_bzero(result, str);
	return (result);
}