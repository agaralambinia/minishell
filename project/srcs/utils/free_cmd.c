/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:14:06 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/23 17:29:01 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_cmd(void *data)
{
	t_cmd	*com;	
	
	com = (t_cmd *)data;
	if (com)
	{
		ft_lstclear(&(com->args), &free);
		ft_lstclear(&(com->redir_in), &free);
		ft_lstclear(&(com->redir_out), &free);
		free(com);
	}	
}
