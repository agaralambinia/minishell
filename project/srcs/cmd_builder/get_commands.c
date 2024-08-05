/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/05 21:23:58 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	init_data(t_wordhan **handler, t_cmd **com)
{
	*handler = get_word_handler();
	*com = get_new_command();
}

t_list	*get_commands(t_list *token_lst, t_envp *envp_var)
{
	t_wordhan	*handler;
	t_cmd		*com;
	t_list		*com_lst;
	void		*info_cont[2];

	com_lst = NULL;
	init_data(&handler, &com);
	if (!handler || !com)
		return (NULL);
	info_cont[1] = handler;
	while (token_lst)
	{
		info_cont[0] = (t_tn *)(token_lst->dt);
		if (!handle_token(info_cont, &com, &com_lst, envp_var))
		{
			free_res(&com_lst, &com, handler);
			return (NULL);
		}
		token_lst = token_lst->next;
	}
	if (!add_command(com, &com_lst, handler, false))
		free_cmd(com);
	free(handler);
	return (com_lst);
}
