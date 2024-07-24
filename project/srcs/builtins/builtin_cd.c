/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:49 by defimova          #+#    #+#             */
/*   Updated: 2024/07/11 17:26:33 by sosokin          ###   ########.fr       */
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
	else if (argv[1] && !ft_strncmp(argv[1], "-", 2))
	{
		directory = get_envp_list_val("OLDPWD", &(envp_var->envp_list));
		if (directory == NULL)
			ft_print_error(SHELL_NAME, "cd", NULL, "OLDPWD not set");
	}
	else if (ft_strlen(argv[1]) == 0)
		directory = ".";
	else
		directory = argv[1];
	return (directory);
}

int	handle_cwd_err(char *prev_pwd, char *dir, t_envp *envp_var)
{
	char	*broken_dir;
	int		res;
	char	*tmp;

	ft_print_error_errno(SHELL_NAME, "cd: error retrieving current \
directory: getcwd: cannot access parent directories", NULL);
	tmp = ft_strjoin("/", dir);
	broken_dir = ft_strjoin(prev_pwd, tmp);
	free(tmp);
	res = env_set_env("PWD", broken_dir, envp_var);
	free(broken_dir);
	return (res);
}

static int	update_working_directory(t_envp *envp_var, char *dir)
{
	char	buffer[PATH_MAX];
	char	*prev_pwd;
	int		res;

	prev_pwd = get_envp_list_val("PWD", &envp_var->envp_list);
	if (get_env_val("OLDPWD", envp_var) == NULL)
		ft_list_remove(oldpwd, &(envp_var->envp_list));
	if (prev_pwd)
	{
		if (env_set_env("OLDPWD", prev_pwd, envp_var) == ERROR)
			return (ERROR);
	}
	else
		env_unset_var("OLDPWD", envp_var);
	if (getcwd(buffer, sizeof(buffer)) == NULL)
		return (handle_cwd_err(prev_pwd, dir, envp_var));
	if (!ft_strcmp(dir, "//"))
		res = env_set_env("PWD", dir, envp_var);
	else
		res = env_set_env("PWD", buffer, envp_var);
	if (res == ERROR)
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
	if (update_working_directory(envp_var, directory) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
