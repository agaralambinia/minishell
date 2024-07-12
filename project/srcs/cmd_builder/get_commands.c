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

static void	set_field(t_wordhan *handler, char val, int setmode)
{
	handler->redir = val;
	if (setmode)
		handler->is_redir_mode = 1;
}

static t_cmd	*add_command(t_cmd *com, t_list **com_lst, t_wordhan *handler)
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

static int handle_envp(char *envname, t_wordhan *handler, t_envp *envp_var)
{
	char	*env_val;
	int		res;

	env_val = get_env_val(envname, envp_var);	
	if (!env_val)
		return (1);
	res = add_to_word(env_val, handler);
	return (res);
}

static int	handle_token(
		t_token *token, t_cmd **com, t_wordhan *handler, t_list **com_lst,  t_envp *envp_var)
{
	int	type;
	int	res;

	res = 1;
	type = token->token_type;
	if (type == WORD || type == HARDWORD || type == SOFTWORD)
		res = add_to_word(token->t_data, handler);
	else if (type == SINGLE_RA)
		set_field(handler, 'o', 0);
	else if (type == DOUBLE_RA)
		set_field(handler, 'o', 1);
	else if (type == SINGLE_LA)
		set_field(handler, 'i', 0);
	else if (type == DOUBLE_LA)
		set_field(handler, 'i', 1);
	else if (type == PIPE)
	{
		*com = add_command(*com, com_lst, handler);
		res = *com != NULL;
	}
	else if (type == ENVP)
		res = handle_envp(token->t_data, handler, envp_var);
	else if (type == SPACE)
		res = bind_field(*com, handler);
	else if (type == EXITSTATUS)
		res = add_to_word(token->t_data, handler);
	return res;
}

t_list	*get_commands(t_envp *envp_var)
{
	t_list		*token_lst;
	t_token		*token;
	t_wordhan	*handler;
	t_cmd		*com;
	t_list		*com_lst;

	com_lst = NULL;
	token_lst = envp_var->token_list;
	handler = get_word_handler();
	com = get_new_command();
	if (!handler || !com)
		return (NULL);
	while (token_lst)
	{
		token = (t_token *)(token_lst->content);
		if (!handle_token(token, &com, handler, &com_lst, envp_var))
		{
			free_res(&com_lst, &com);
			return (NULL);	
		}
		token_lst = token_lst->next;
	}
	com = add_command(com, &com_lst, handler);
	free(com);
	free(handler);
//	system("leaks minishell");
	return (com_lst);
}
