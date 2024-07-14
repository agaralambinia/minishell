/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:17:04 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/14 22:17:23 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_cmd	*add_command(t_cmd *com, t_list **com_lst, t_wordhan *handler)
{
	t_list	*com_node;
	int		res;

	res = 0;
	res = bind_field(com, handler);
	com_node = ft_lstnew(com);
	if (!res || !com_node)
		return (NULL);
	ft_lstadd_back(com_lst, com_node);
	handler->word = NULL;
	handler->field = 'c';
	handler->redir = 0;
	handler->is_redir_mode = 0;
	com = get_new_command();
	return (com);
}
