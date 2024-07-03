#include "../../incs/minishell.h"

static void	print_environment_vars(void);
static bool	is_valid_arg(char *arg);

int	builtin_export(int argc, char **argv)
{
	int	exit_status;
	int	index;

	exit_status = EXIT_SUCCESS;
	if (argc == 1)
		print_environment_vars();
	index = 1;
	while (argc > 1 && argv[index])
	{
		if (is_valid_arg(argv[index]) == false)
		{
			print_error(SHELL_NAME, argv[index], NULL, "not a valid identifier");
			exit_status = EXIT_FAILURE;
		}
		else if (ft_strchr(argv[index], '='))
			env_put_var(argv[index]);
		index++;
	}
	return (exit_status);
}

static void	print_environment_vars(void)
{
	char	**env_copy;
	int		var_name_len;
	int		index;

	if (g_env == NULL || *g_env == NULL)
		return ;
	env_copy = malloc((split_count(g_env) + 1) * sizeof(char *));
	if (env_copy == NULL)
	{
		print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
		return ;
	}
	env_copy = ft_memcpy(env_copy, g_env,
			(split_count(g_env) + 1) * sizeof(char *));
	split_sort(env_copy);
	index = 0;
	while (env_copy[index])
	{
		var_name_len = ft_strchr(env_copy[index], '=') - env_copy[index];
		printf("%.*s", var_name_len + 1, env_copy[index]);
		printf("\"%s\"\n", env_get_value(env_copy[index]));
		index++;
	}
	free(env_copy);
}

static bool	is_valid_arg(char *arg)
{
	int	index;

	if (arg[0] == '\0' || arg[0] == '=')
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '=' && env_is_var_char(arg[index]))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}
