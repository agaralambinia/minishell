/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:14:45 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/07 19:34:49 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	redir_out(t_cmd *cmd)
{
	int	fd;

	if (cmd->output)
	{
		if (cmd->outmode)
			fd = open(cmd->output, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else
			fd = open(cmd->output, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd < 0)
		{
			perror(cmd->command);
			exit(1);
		}
		dup2(fd, 1);
		close(fd);
	}
}
