/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:17:04 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/05 21:22:37 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_cmd	*add_command(
	t_cmd *com, t_list **com_lst, t_wordhan *handler, bool create)
{
	t_list	*com_node;
	int		res;

	res = 0;
	res = bind_field(com, handler);
	if (!res || !(com->command))
		return (NULL);
	com_node = ft_lstnew(com);
	if (!com_node)
		return (NULL);
	ft_lstadd_back(com_lst, com_node);
	handler->word = NULL;
	handler->field = 'c';
	handler->redir = 0;
	handler->is_redir_mode = 0;
	if (create)
		com = get_new_command();
	return (com);
}
