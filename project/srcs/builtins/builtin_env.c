#include "builtin.h"

int	builtin_env(int argc __attribute((unused)),
	char **argv __attribute((unused)))
{
	int	index;

	if (g_env == NULL)
	{
		print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (EXIT_FAILURE);
	}
	index = 0;
	while (g_env[index])
	{
		ft_putendl_fd(g_env[index], STDOUT_FILENO);
		index++;
	}
	return (0);
}
