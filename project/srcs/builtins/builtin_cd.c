#include "../../incs/minishell.h"

static char	*determine_directory(int argc, char **argv)
{
	char	*directory;

	directory = NULL;
	if (argc == 1)
	{
		directory = env_get_value("HOME");
		if (directory == NULL)
			print_error(SHELL_NAME, "cd", NULL, "HOME not set");
	}
	else if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
	{
		directory = env_get_value("OLDPWD");
		if (directory == NULL)
			print_error(SHELL_NAME, "cd", NULL, "OLDPWD not set");
	}
	else
		directory = argv[1];
	return (directory);
}

static int	update_working_directory(t_envp *envp_var)
{
	char	buffer[PATH_MAX];

	if (env_get_value("PWD"))
	{
		if (env_set_env("OLDPWD", env_get_value("PWD"), envp_var) == ERROR)
			return (ERROR);
	}
	else
		env_unset_var("OLDPWD", envp_var);
	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		print_error_errno(SHELL_NAME, "cd", NULL);
		return (ERROR);
	}
	if (env_set_env("PWD", buffer, envp_var) == ERROR)
		return (ERROR);
	return (0);
}

int	builtin_cd(int argc, char **argv, t_envp *envp_var)
{
	char	*directory;

	directory = determine_directory(argc, argv);
	if (directory == NULL)
		return (EXIT_FAILURE);
	if (chdir(directory) == -1)
	{
		print_error_errno(SHELL_NAME, "cd", directory);
		return (EXIT_FAILURE);
	}
	if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
		ft_putendl_fd(directory, STDOUT_FILENO);
	if (update_working_directory(envp_var) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
