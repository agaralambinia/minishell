/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:38:35 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/07 19:34:59 by sosokin          ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */

#include "../../incs/minishell.h"

char	**get_env_arr()
{
	char	**arr;
	int		len;
	int		i;
	t_list	*tmp;

	len = ft_lstsize(g_envp->envp_list);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	tmp = g_envp->envp_list;
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

void	run(char **paths, char **args)
{
	char	*prog_path;
	char	**env_arr;

	prog_path = get_prog_path(paths, args[0]);
	env_arr = get_env_arr();
	execve(prog_path, args, env_arr);
	perror(args[0]);
//	write(2, "ERROR\n", 6);
	exit(1);
}
