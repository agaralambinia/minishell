/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/22 17:43:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_field(t_wordhan *handler, char val, int setmode)
{
	handler->redir = val;
	if (setmode)
		handler->is_redir_mode = 1;
}

static t_cmd	*add_command(t_cmd *com, t_list **com_lst, t_wordhan *handler)
{
	t_list		*com_node;

	bind_field(com, handler);
	com_node = ft_lstnew(com);
	ft_lstadd_back(com_lst, com_node);
	handler->word = NULL;
	handler->field = 'c';
	handler->redir = 0;
	handler->is_redir_mode = 0;
	com = get_new_command();
	return (com);
}

static void	handle_envp(char *envname, t_wordhan *handler)
{
	char	*env_val;

	env_val = get_env_val(envname);	
	add_to_word(env_val, handler);
}

static void	handle_token(
		t_token *token, t_cmd **com, t_wordhan *handler, t_list **com_lst)
{
	int	type;

	type = token->token_type;
	if (type == WORD || type == HARDWORD || type == SOFTWORD)
		add_to_word(token->token_content, handler);
	else if (type == SINGLE_RA)
		set_field(handler, 'o', 0);
	else if (type == DOUBLE_RA)
		set_field(handler, 'o', 1);
	else if (type == SINGLE_LA)
		set_field(handler, 'i', 0);
	else if (type == DOUBLE_LA)
		set_field(handler, 'i', 1);
	else if (type == PIPE)
		*com = add_command(*com, com_lst, handler);
	else if (type == ENVP)
		handle_envp(token->token_content, handler);
	else if (type == SPACE)
		bind_field(*com, handler);
}

t_list	*get_commands()
{
	t_list		*token_lst;
	t_token		*token;
	t_wordhan	*handler;
	t_cmd		*com;
	t_list		*com_lst;

	com_lst = NULL;
	token_lst = g_envp->token_list;
	handler = get_word_handler();
	com = get_new_command();
	while (token_lst)
	{
		token = (t_token *)(token_lst->content);
		handle_token(token, &com, handler, &com_lst);
		token_lst = token_lst->next;
	}
	add_command(com, &com_lst, handler);
	free(handler);
	return (com_lst);
}
