/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:38 by defimova          #+#    #+#             */
/*   Updated: 2024/07/09 19:38:37 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void builtins_init(char *builtins[])
{
	builtins[0] = "cd";
	builtins[1] = "echo";
	builtins[2] = "env";
	builtins[3] = "export";
	builtins[4] = "pwd";
	builtins[5] = "unset";
	builtins[6] = NULL;
}

static int	builtin_check(char **argv)
{
	int		name_length;
	int		index;
	char	*builtins[7];

	builtins_init(builtins);
	index = 0;
	if (argv[0] && !ft_strncmp(argv[0], "exit", 5))
		return (INT_MAX);
	while (builtins[index])
	{
		name_length = ft_strlen(builtins[index]);
		if (argv[0] && !ft_strncmp(argv[0], builtins[index], name_length + 1))
			return (index + 1);
		index++;
	}
	return (0);
}

int	builtin_exec(char **argv, bool subshell, t_envp *envp_var)
{
	int	builtin_index;

	(void)subshell;
	builtin_index = builtin_check(argv);
	if (builtin_index == 0)
		return (NOTFOUND);
	else if (builtin_index == INT_MAX)
		return (INT_MAX);
	//errno = 0; TODO подозреваю это exit code
	if (!(ft_strncmp(argv[0], "cd", 2)))
		return (builtin_cd(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "echo", 4)))
		return (builtin_echo(argv));
	else if (!(ft_strncmp(argv[0], "env", 3)))
		return (builtin_env(envp_var));
	else if (!(ft_strncmp(argv[0], "export", 6)))
		return (builtin_export(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "pwd", 3)))
		return (builtin_pwd());
	else if (!(ft_strncmp(argv[0], "unset", 5)))
		return (builtin_unset(argv, envp_var));
	else
		return (ERROR);
}
