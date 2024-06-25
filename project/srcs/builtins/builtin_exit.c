#include "builtin.h"
#include "exec.h"

static bool	is_numeric(char *str);

int	builtin_exit(int argc, char **argv, bool subshell, t_list *free_list)
{
	int	exit_code;

	if (!subshell && isatty(STDERR_FILENO))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	exit_code = exec_exit_status_get();
	if (argc >= 2 && is_numeric(argv[1]) == false)
		exit_code = 255;
	else if (argc == 2)
		exit_code = ft_atoi(argv[1]);
	else if (argc > 2)
	{
		print_error(SHELL_NAME, "exit", NULL, "too many arguments");
		return (EXIT_FAILURE);
	}
	exec_free_all(argv, free_list);
	exit(exit_code);
}

static bool	is_numeric(char *str)
{
	int	index;

	index = 0;
	if (str[0] == '\0')
	{
		print_error(SHELL_NAME, "exit", str, "numeric argument required");
		return (false);
	}
	else if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
		{
			print_error(SHELL_NAME, "exit", str, "numeric argument required");
			return (false);
		}
		index++;
	}
	return (true);
}
