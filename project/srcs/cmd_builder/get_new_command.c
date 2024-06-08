/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:50:47 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/02 19:10:09 by sosokin          ###   ########.fr       */
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
	com->input = 0;
	com->command = NULL;
	com->args = NULL;
	com->output = NULL;
	com->inmode = 0;
	com->outmode = 0;
	return (com);
}
