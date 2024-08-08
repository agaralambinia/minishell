/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:38:35 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/06 21:53:21 by sosokin          ###   ########.fr       */
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
		arr[i] = (char *)(tmp->dt);
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
	if (ft_strchr(name, '/'))
		return (name);
	return (NULL);
}

static void	print_error(char *prog_path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(prog_path, 2);
	if (ft_strchr(prog_path, '/'))
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}

static int	exec_by_path(char **args, t_envp *envp_var)
{
	char	*prog_path;
	int		res;
	char	**paths;
	char	**env_arr;

	paths = ft_split(get_env_val("$PATH", envp_var), ':');
	prog_path = get_prog_path(paths, args[0]);
	if (!prog_path)
		print_error(args[0]);
	else
	{
		env_arr = get_env_arr(envp_var);
		if (execve(prog_path, args, env_arr) == -1)
			print_error(prog_path);
		else
			perror(args[0]);
	}
	res = 127;
	if (paths)
		free_arr((void **)paths);
	return (res);
}

void	run(char **args, t_envp *envp_var)
{
	int		res;

	if (!args[0])
		exit(0);
	res = builtin_exec(args, envp_var, NULL);
	if (res == NOTFOUND)
		res = exec_by_path(args, envp_var);
	exit(res);
}
