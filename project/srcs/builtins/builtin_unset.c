#include "../../incs/minishell.h"

int	builtin_unset(int argc __attribute((unused)), char **argv)
{
	int	exit_status;
	int	arg_index;
	int	char_index;

	exit_status = 0;
	arg_index = 1;
	while (argv[arg_index])
	{
		char_index = 0;
		while (argv[arg_index][char_index] && env_is_var_char(argv[arg_index][char_index]))
			char_index++;
		if (argv[arg_index][char_index] != '\0' || argv[arg_index][0] == '\0')
		{
			print_error(SHELL_NAME, "unset", argv[arg_index], "not a valid identifier");
			exit_status = EXIT_FAILURE;
		}
		else
			env_unset_var(argv[arg_index]);
		arg_index++;
	}
	return (exit_status);
}
