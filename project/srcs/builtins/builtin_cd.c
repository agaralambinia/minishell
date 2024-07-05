/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:49 by defimova          #+#    #+#             */
/*   Updated: 2024/07/05 20:54:50 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*determine_directory(int argc, char **argv, t_envp *envp_var)
{
	char	*directory;

	directory = NULL;
	if (argc == 1)
	{
		directory = get_envp_list_val("HOME", &envp_var->envp_list);
		if (directory == NULL)
			ft_print_error(SHELL_NAME, "cd", NULL, "HOME not set");
	}
	else if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
	{
		directory = get_envp_list_val("OLDPWD", &(envp_var->envp_list));
		if (directory == NULL)
			ft_print_error(SHELL_NAME, "cd", NULL, "OLDPWD not set");
	}
	else
		directory = argv[1];
	return (directory);
}

static int	update_working_directory(t_envp *envp_var)
{
	char	buffer[PATH_MAX];

	if (get_envp_list_val("PWD", &envp_var->envp_list))
	{
		if (env_set_env("OLDPWD", get_envp_list_val(
			"PWD", &(envp_var->envp_list)), envp_var) == ERROR)
			return (ERROR);
	}
	else
		env_unset_var("OLDPWD", envp_var);
	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		ft_print_error_errno(SHELL_NAME, "cd", NULL);
		return (ERROR);
	}
	if (env_set_env("PWD", buffer, envp_var) == ERROR)
		return (ERROR);
	return (0);
}

int	builtin_cd(int argc, char **argv, t_envp *envp_var)
{
	char	*directory;

	directory = determine_directory(argc, argv, envp_var);
	if (directory == NULL)
		return (EXIT_FAILURE);
	if (chdir(directory) == -1)
	{
		ft_print_error_errno(SHELL_NAME, "cd", directory);
		return (EXIT_FAILURE);
	}
	if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
		ft_putendl_fd(directory, STDOUT_FILENO);
	if (update_working_directory(envp_var) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
