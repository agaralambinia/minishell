/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:44:34 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/23 16:49:47 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_res(t_list **com_lst, t_cmd **com, t_wordhan *handler)
{
	if (com_lst)
		ft_lstclear(com_lst, &free);
	if (*com)
		free(*com);
	if (handler)
		free(handler);
}
