/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:50:47 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/09 17:03:57 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_cmd	*get_new_command(char *field)
{
	t_cmd	*com;

	field[0] = 'c';
	field[1] = 0;
	field[2] = 0;
	com = (t_cmd *)safe_malloc(sizeof(t_cmd));
	com->redir_in = NULL;
	com->command = NULL;
	com->args = NULL;
	com->redir_out = NULL;
	return (com);
}
