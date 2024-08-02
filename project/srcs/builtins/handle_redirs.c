/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:39:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/01 22:47:39 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	handle_redirs(t_cmd *cmd)
{
	int fd;

	fd = STDOUT_FILENO;
	if (cmd)
	{
		if (handle_in_redir(cmd) == ERROR)
			return (-1);
		unlink("here_doc");
		fd = handle_out_redir(cmd);
	}
	return (fd);
}