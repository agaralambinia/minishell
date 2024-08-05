/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:19:33 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/04 21:31:45 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	run_single(t_list *commands, t_envp *envp_var)
{
	char	**args;
	t_cmd	*cmd;
	int		exit_code;

	cmd = (t_cmd *)(commands->dt);
	args = get_args(cmd);
	exit_code = builtin_exec(args, envp_var, cmd);
	free_arr((void **)args);
	if (exit_code == NOTFOUND)
		exit_code = run_command(commands, envp_var);
	return (exit_code);
}
