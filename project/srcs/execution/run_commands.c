/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:02:15 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/06 17:17:40 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	run_first(t_cmd *cmd, int **pp, t_envp *envp_var)
{
	char	**args;

	setup_pipes_first(pp);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	signal(SIGQUIT, SIG_DFL);
	run(args, envp_var);
}

static void	run_last(t_cmd *cmd, int cmd_cnt, int **pp, t_envp *envp_var)
{
	char	**args;
	t_list	*tmp;

	tmp = cmd->redir_in;
	if (!tmp || !((t_r *)(tmp->dt))->m)
		setup_pipes_last(pp, cmd_cnt - 2);
	redir_in(cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(args, envp_var);
}

static int	run_pipeline(
	int cmd_cnt, t_list *cmd_lst, int **pp, t_envp *envp_var)
{
	int		i;
	t_cmd	*cmd;
	t_list	*tmp;
	int 	pid;

	i = 0;
	tmp = cmd_lst;
	while (tmp && i < CHILD_MAX)
	{
		cmd = (t_cmd *)(tmp->dt);
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				run_first(cmd, pp, envp_var);
			else if (i == cmd_cnt - 1)
				run_last(cmd, cmd_cnt, pp, envp_var);
			else
				run_mid(cmd, pp, i, envp_var);
		}
		i++;
		tmp = tmp->next;
	}
	return (pid);
}

static int wait_all(int pid_last)
{
	int last_exit_info;
	int pid;
	int	exit_info;

	while (1)
	{
		pid = wait(&exit_info);
		if (pid_last == pid)
			last_exit_info = exit_info;
		else if (pid == -1)
			break;
	}
	return (last_exit_info);
}

int	run_command(t_list *cmd_lst, t_envp *envp_var)
{
	int		**pp;
	int		cmd_cnt;
	bool	is_fork_ov;
	int 	last_exit_info;
	int		pid_last;

	cmd_cnt = ft_lstsize(cmd_lst);
	pp = get_pipes(cmd_cnt);
	if (!pp)
		return (1);
	pid_last = run_pipeline(cmd_cnt, cmd_lst, pp, envp_var);
	setup_pipes_parent(pp);
	signal(SIGINT, SIG_IGN);
	last_exit_info = wait_all(pid_last);
	is_fork_ov = cmd_cnt > CHILD_MAX;
	ft_singals();
	free_arr((void **)pp);
	unlink("here_doc");
	return (get_exit(last_exit_info, is_fork_ov));
}
