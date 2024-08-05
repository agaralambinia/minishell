/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:14:06 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/04 21:33:49 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_cmd(void *data)
{
	t_cmd	*com;	

	com = (t_cmd *)data;
	if (com)
	{
		free(com->command);
		ft_lstclear(&(com->args), &free);
		ft_lstclear(&(com->redir_in), &free_redir);
		ft_lstclear(&(com->redir_out), &free_redir);
		free(com);
	}
}
