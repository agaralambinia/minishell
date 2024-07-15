/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:14:45 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/22 21:29:32 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	redir_out(t_cmd *cmd)
{
	int		fd;
	t_list	*tmp;
	t_r		*cur;

	tmp = cmd->redir_out;
	while (tmp)
	{
		cur = (t_r *)(tmp->dt);
		if (cur->m)
			fd = open(cur->path, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else
			fd = open(cur->path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		check_for_exit(cmd->command, fd < 0);
		dup2(fd, 1);
		close(fd);
		tmp = tmp->next;
	}
}
