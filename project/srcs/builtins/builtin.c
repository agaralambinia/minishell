/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:38 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 19:23:39 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_exec(char **argv, bool subshell, t_envp *envp_var)
{
	(void)subshell;
	if (!(ft_strncmp(argv[0], "cd", 2)))
		return (builtin_cd(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "echo", 4)))
		return (builtin_echo(argv));
	else if (!(ft_strncmp(argv[0], "env", 3)))
		return (builtin_env(envp_var));
	else if (!(ft_strncmp(argv[0], "export", 6)))
		return (builtin_export(ft_split_count(argv), argv, envp_var));
	else if (!(ft_strncmp(argv[0], "pwd", 3)))
		return (builtin_pwd(envp_var));
	else if (!(ft_strncmp(argv[0], "unset", 5)))
		return (builtin_unset(argv, envp_var));
	else if (!(ft_strncmp(argv[0], "exit", 4)))
		return (builtin_exit(argv, envp_var));
	else
		return (NOTFOUND);
}
