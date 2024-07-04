#include "../../incs/minishell.h"

int	builtin_pwd(int argc __attribute((unused)),
	char **argv __attribute((unused)),
	t_envp *envp_var __attribute((unused)))
{
	char	path_buffer[PATH_MAX];

	if (getcwd(path_buffer, sizeof(path_buffer)))
	{
		ft_putendl_fd(path_buffer, STDOUT_FILENO);
		return (SUCCESS);
	}
	else
	{
		print_error_errno(SHELL_NAME, "pwd", NULL);
		return (ERROR);
	}
}
