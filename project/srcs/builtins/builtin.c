/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:38 by defimova          #+#    #+#             */
/*   Updated: 2024/07/05 20:54:40 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	builtin_check(char **argv)
{
	int			name_length;
	int			index;
	const char	builtins[6][20] = {
		"cd", "echo", "env", "export", "pwd", "unset"};

	index = 0;
	if (argv[0] && !ft_strncmp(argv[0], "exit", 5))
		return (INT_MAX);
	while (builtins[index])
	{
		name_length = ft_strlen(builtins[index]);
		printf("Get len\n");
		if (argv[0] && !ft_strncmp(argv[0], builtins[index], name_length + 1))
		{
			printf("Find command\n");
			return (index + 1);
		}
		printf("Not find command\n");
		index++;
	}
	return (0);
}

int	builtin_exec(char **argv, bool subshell, t_envp *envp_var)
{
	int	builtin_index;

	(void)subshell;
	builtin_index = builtin_check(argv);
	printf("index is %d\n", builtin_index);
	if ((builtin_index == 0) || (builtin_index == INT_MAX))
	{
		return (ERROR);
	}
	//errno = 0; TODO подозреваю это exit code
	if (!(ft_strncmp(argv[0], "cd", 2)))
		return (builtin_cd(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "echo", 4)))
		return (builtin_echo(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "env", 3)))
		return (builtin_env(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "export", 6)))
		return (builtin_export(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "pwd", 3)))
		return (builtin_pwd(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "unset", 5)))
		return (builtin_unset(ft_split_count(argv), argv, envp_var));
	else
		return (ERROR);
}
