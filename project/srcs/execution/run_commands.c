/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:02:15 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/06 15:58:12 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	run_first(t_cmd *cmd, int **pp, char **paths, t_envp *envp_var)
{
	char	**args;

	printf("%s %d\n", __FILE__, __LINE__);
	setup_pipes_first(pp);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(paths, args, envp_var);
}

static void	run_mid(t_cmd *cmd, int **pp, int ind, char **paths, t_envp *envp_var)
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
	run(paths, args, envp_var);
}

static void	run_last(t_cmd *cmd, int cmd_cnt, int **pp, char **paths, t_envp *envp_var)
{
	char	**args;

	setup_pipes_last(pp, cmd_cnt - 2);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(paths, args, envp_var);
}

static int	run_pipeline(int cmd_cnt, t_list *cmd_lst, int **pp, char **paths, t_envp *envp_var)
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
				run_first(cmd, pp, paths, envp_var);
		}
		else if (i == cmd_cnt - 1)
		{
			if (fork() == 0)
				run_last(cmd, cmd_cnt, pp, paths, envp_var);
		}
		else
		{
			if (fork() == 0)
				run_mid(cmd, pp, i, paths, envp_var);
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	run_command(t_list *cmd_lst, t_envp *envp_var)
{
	char	**paths;
	int		**pp;
	int		cmd_cnt;
	int		i;
	int		exit_info;

	printf("%s %d\n", __FILE__, __LINE__);
	paths = ft_split(get_env_val("$PATH", envp_var), ':');
	cmd_cnt = ft_lstsize(cmd_lst);
	pp = get_pipes(cmd_cnt);
	if (!pp)
		return (1);
	i = run_pipeline(cmd_cnt, cmd_lst, pp, paths, envp_var);
	setup_pipes_parent(pp);
	while (i >= 0)
	{
		wait(&exit_info);
		i--;
	}
	if (paths)
		free_arr((void **)paths);
	free_arr((void **)pp);
	unlink("here_doc");
	if (WIFEXITED(exit_info))
		return (WEXITSTATUS(exit_info));
	else if (WTERMSIG(exit_info) == 2)
		return (130);
	return (0);
}
