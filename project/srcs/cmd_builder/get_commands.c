/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/12 15:37:08 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	init_data(
	t_list **token_lst, t_wordhan **handler, t_cmd **com, t_envp *envp_var)
{
	*token_lst = envp_var->token_list;
	*handler = get_word_handler();
	*com = get_new_command();
}

t_list	*get_commands(t_envp *envp_var)
{
	t_list		*token_lst;
	t_wordhan	*handler;
	t_cmd		*com;
	t_list		*com_lst;
	void		*info_cont[2];

	com_lst = NULL;
	init_data(&token_lst, &handler, &com, envp_var);
	if (!handler || !com)
		return (NULL);
	info_cont[1] = handler;
	while (token_lst)
	{
		info_cont[0] = (t_token *)(token_lst->content);
		if (!handle_token(info_cont, &com, &com_lst, envp_var))
		{
			free_res(&com_lst, &com, handler);
			return (NULL);
		}
		token_lst = token_lst->next;
	}
	com = add_command(com, &com_lst, handler);
	free_res(&com_lst, &com, handler);
	return (com_lst);
}
