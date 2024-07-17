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

	i = 0;
	tmp = cmd_lst;
	while (tmp)
	{
		cmd = (t_cmd *)(tmp->dt);
		if (fork() == 0)
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
	return (i);
}

int	get_exit(int exit_info)
{
	if (WIFEXITED(exit_info))
		return (WEXITSTATUS(exit_info));
	else if (WTERMSIG(exit_info) == 2)
		return (130);
	else if (WTERMSIG(exit_info) == 3)
	{
		printf("Quit: 3\n");
		return (131);
	}
	return (0);
}

int	run_command(t_list *cmd_lst, t_envp *envp_var)
{
	int	**pp;
	int	i;
	int	exit_info;
	int	cmd_cnt;

	cmd_cnt = ft_lstsize(cmd_lst);
	pp = get_pipes(cmd_cnt);
	if (!pp)
		return (1);
	i = run_pipeline(cmd_cnt, cmd_lst, pp, envp_var);
	setup_pipes_parent(pp);
	signal(SIGINT, SIG_IGN);
	while (i >= 0)
	{
		wait(&exit_info);
		i--;
	}
	ft_singals();
	free_arr((void **)pp);
	unlink("here_doc");
	return (get_exit(exit_info));
}
