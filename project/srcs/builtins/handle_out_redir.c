/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_out_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:05:20 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/02 20:31:23 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	handle_out_redir(t_cmd *cmd)
{
	int		fd;
	t_list	*tmp;
	t_r		*cur;

	tmp = cmd->redir_out;
	fd = STDOUT_FILENO;
	while (tmp)
	{
		if (fd > 2)
			close(fd);
		cur = (t_r *)(tmp->dt);
		if (cur->m)
			fd = open(cur->path, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else
			fd = open(cur->path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (check_for_error(cmd->command, fd < 0))
			return (fd);
		tmp = tmp->next;
	}
	return (fd);
}
