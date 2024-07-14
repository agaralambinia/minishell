/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:38:35 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/09 19:41:21 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	**get_env_arr(t_envp *envp_var)
{
	char	**arr;
	int		len;
	int		i;
	t_list	*tmp;

	len = ft_lstsize(envp_var->envp_list);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	tmp = envp_var->envp_list;
	while (i < len)
	{
		arr[i] = (char *)(tmp->content);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

static char	*get_prog_path(char **paths, char *name)
{
	char	*res;
	char	*path;

	if (paths)
	{
		while (*paths)
		{
			path = ft_strjoin(*paths, "/");
			res = ft_strjoin(path, name);
			free(path);
			if (access(res, F_OK) == 0)
				return (res);
			paths++;
		}
	}
	return (name);
}

void	run(char **args, t_envp *envp_var)
{
	char	*prog_path;
	char	**env_arr;
	int		builtin_res;
	char	**paths;

	paths = ft_split(get_env_val("$PATH", envp_var), ':');
	builtin_res = builtin_exec(args, 0, envp_var);
	if (builtin_res == NOTFOUND)
	{
		prog_path = get_prog_path(paths, args[0]);
		env_arr = get_env_arr(envp_var);
		if (execve(prog_path, args, env_arr) == -1)
			printf("minishell: %s: command not found\n", prog_path);
		else
			perror(args[0]);
		if (paths)
			free_arr((void **)paths);
		exit(127);
	}
	else
	{
		if (paths)
			free_arr((void **)paths);
		exit(builtin_res);
	}
}
