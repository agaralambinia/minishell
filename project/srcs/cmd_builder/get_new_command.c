/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:50:47 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/16 14:15:41 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_cmd	*get_new_command(void)
{
	t_cmd	*com;

	com = (t_cmd *)safe_malloc(sizeof(t_cmd));
	com->redir_in = NULL;
	com->command = NULL;
	com->args = NULL;
	com->redir_out = NULL;
	return (com);
}
