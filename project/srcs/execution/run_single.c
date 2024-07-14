/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:19:33 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/14 12:19:37 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	run_single(t_list *commands, t_envp *envp_var)
{
	char	**args;
	int		is_any_redir;
	t_cmd	*cmd;
	int		exit_code;

	cmd = (t_cmd *)(ft_lstlast(commands)->content);
	is_any_redir = ft_lstsize(cmd->redir_out);
	if (!is_any_redir)
	{
		args = get_args((t_cmd *)(commands->content));
		exit_code = builtin_exec(args, 0, envp_var);
		free((void *)args);
		if (exit_code == NOTFOUND)
			exit_code = run_command(commands, envp_var);
	}
	else
		exit_code = run_command(commands, envp_var);
	return (exit_code);
}
