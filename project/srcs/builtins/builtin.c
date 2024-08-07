/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:54:38 by defimova          #+#    #+#             */
/*   Updated: 2024/08/05 21:43:42 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_exec(char **argv, t_envp *envp_var, t_cmd *cmd)
{
	if (!(argv[0]))
		return (NOTFOUND);
	else if (!(ft_strncmp(argv[0], "cd", 3)))
		return (builtin_cd(ft_split_count(argv), argv, envp_var, cmd));
	else if (!(ft_strncmp(argv[0], "echo", 5)))
		return (builtin_echo(argv, cmd));
	else if (!(ft_strncmp(argv[0], "env", 4)))
		return (builtin_env(envp_var, cmd));
	else if (!(ft_strncmp(argv[0], "export", 7)))
		return (builtin_export(ft_split_count(argv), argv, envp_var, cmd));
	else if (!(ft_strncmp(argv[0], "pwd", 4)))
		return (builtin_pwd(envp_var, cmd));
	else if (!(ft_strncmp(argv[0], "unset", 6)))
		return (builtin_unset(argv, envp_var, cmd));
	else if (!(ft_strncmp(argv[0], "exit", 5)))
		return (builtin_exit(argv, envp_var, cmd));
	return (NOTFOUND);
}
