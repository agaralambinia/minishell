/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/01 20:52:17 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_field(char *field, char val, int setmode)
{
	field[1] = val;
	if (setmode)
		field[2] = 1;
}

static t_command	*add_command(t_command *com, t_list **com_lst, char *field)
{
	t_list		*com_node;

	com_node = ft_lstnew(com);
	ft_lstadd_back(com_lst, com_node);
	com = get_new_command(field);
	return (com);
}

static void	handle_envp(char *envname, t_command *com, char *field)
{
	t_list		*tmp;
	char		*env_val;

	tmp = g_envp->envp_list;
	while (tmp)
	{
		if (ft_strbegins(tmp->content, envname + 1))
		{
			env_val = get_env_val(envname);	
			bind_field(com, env_val, field);
			break;
		}
		tmp = tmp->next;
	}
}

static void	handle_token(
		t_token *token, t_command **com, char *field, t_list **com_lst)
{
	int	type;

	type = token->token_type;
	if (type == WORD || type == HARDWORD || type == SOFTWORD)
		bind_field(*com, token->token_content, field);
	else if (type == SINGLE_RA)
		set_field(field, 'o', 0);
	else if (type == DOUBLE_RA)
		set_field(field, 'o', 1);
	else if (type == SINGLE_LA)
		set_field(field, 'i', 0);
	else if (type == DOUBLE_LA)
		set_field(field, 'i', 1);
	else if (type == PIPE)
		*com = add_command(*com, com_lst, field);
	else if (type == ENVP)
		handle_envp(token->token_content, *com, field);
}

t_list	*get_commands()
{
	t_list		*token_lst;
	t_token		*token;
	char		field[3];
	t_command	*com;
	t_list		*com_lst;

	com_lst = NULL;
	token_lst = g_envp->token_list;
	com = get_new_command(field);
	while (token_lst)
	{
		token = (t_token *)(token_lst->content);
		handle_token(token, &com, field, &com_lst);
		token_lst = token_lst->next;
	}
	add_command(com, &com_lst, field);
	return (com_lst);
}
