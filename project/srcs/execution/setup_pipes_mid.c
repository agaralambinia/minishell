/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipes_mid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:49:10 by defimova          #+#    #+#             */
/*   Updated: 2024/07/17 19:49:11 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	setup_pipes_mid(int **pp, int ind, t_cmd *cmd)
{
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
	if (cmd->redir_in)
		redir_in(cmd);
	else
		dup2(pp[ind - 1][0], 0);
	close(pp[ind - 1][0]);
	close(pp[ind][0]);
	dup2(pp[ind][1], 1);
	close(pp[ind][1]);
}

void	run_mid(t_cmd *cmd, int **pp, int ind, t_envp *envp_var)
{
	char	**args;

	setup_pipes_mid(pp, ind, cmd);
	redir_out(cmd);
	args = get_args(cmd);
	run(args, envp_var);
}
