/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:02:15 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/11 10:24:32 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_arr(void **arr)
{
	void	**tmp;

	tmp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

static void	run_first(t_cmd *cmd, int **pp, char **paths)
{
	char	**args;

	setup_pipes_first(pp);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(paths, args);
}

static void	run_mid(t_cmd *cmd, int **pp, int ind, char **paths)
{
	char	**args;
	int		i;
	int		len;

	i = 0;
	len = ft_arrlen((void **)pp);
	while (i < len)
	{
		if (i != ind && i != ind - 1)
		{
			close(pp[i][0]);
			close(pp[i][1]);
		}
		i++;
	}
	close(pp[ind - 1][1]);
	dup2(pp[ind - 1][0], 0);
	close(pp[ind - 1][0]);
	close(pp[ind][0]);
	dup2(pp[ind][1], 1);
	close(pp[ind][1]);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(paths, args);
}

static void	run_last(t_cmd *cmd, int cmd_cnt, int **pp, char **paths)
{
	char	**args;

	setup_pipes_last(pp, cmd_cnt - 2);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(paths, args);
}

static int	run_pipeline(int cmd_cnt, t_list *cmd_lst, int **pp, char **paths)
{
	int		i;
	t_cmd	*cmd;
	t_list	*tmp;

	i = 0;
	tmp = cmd_lst;
	while (tmp)
	{
		cmd = (t_cmd *)(tmp->content);
		if (i == 0)
		{
			if (fork() == 0)
				run_first(cmd, pp, paths);
		}
		else if (i == cmd_cnt - 1)
		{
			if (fork() == 0)
				run_last(cmd, cmd_cnt, pp, paths);
		}
		else
		{
			if (fork() == 0)
				run_mid(cmd, pp, i, paths);
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	run_command(t_list *cmd_lst)
{
	char	**paths;
	int		**pp;
	int		cmd_cnt;
	int		i;

	paths = ft_split(get_env_val("$PATH"), ':');
	cmd_cnt = ft_lstsize(cmd_lst);
	pp = get_pipes(cmd_cnt);

	if (!pp)
		return (1);
	i = run_pipeline(cmd_cnt, cmd_lst, pp, paths);
	setup_pipes_parent(pp);
	while (i >= 0)
	{
		wait(NULL);
		i--;
	}
	if (paths)
		free_arr((void **)paths);
	free_arr((void **)pp);
//	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		unlink("here_doc");
	return (0);
}
