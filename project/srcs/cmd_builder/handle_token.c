/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:14:56 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/14 22:14:58 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_field(t_wordhan *handler, char val, int setmode)
{
	handler->redir = val;
	if (setmode)
		handler->is_redir_mode = 1;
}

static int	handle_envp(char *envname, t_wordhan *handler, t_envp *envp_var)
{
	char	*env_val;
	int		res;

	env_val = get_env_val(envname, envp_var);
	if (!env_val)
		return (1);
	res = add_to_word(env_val, handler);
	return (res);
}

static int	handle_pipe(t_cmd **com, t_list **com_lst, t_wordhan *handler)
{
	int	res;

	*com = add_command(*com, com_lst, handler);
	res = *com != NULL;
	return (res);
}

int	handle_token(
	void **info_cont, t_cmd **com, t_list **com_lst, t_envp *envp_var)
{
	int			res;
	t_token		*token;
	t_wordhan	*handler;

	res = 1;
	token = (t_token *)(info_cont[0]);
	handler = (t_wordhan *)(info_cont[0]);
	if (token->token_type == SINGLE_RA)
		set_field(handler, 'o', 0);
	else if (token->token_type == D_RA)
		set_field(handler, 'o', 1);
	else if (token->token_type == SINGLE_LA)
		set_field(handler, 'i', 0);
	else if (token->token_type == D_LA)
		set_field(handler, 'i', 1);
	else if (token->token_type == PIPE)
		res = handle_pipe(com, com_lst, handler);
	else if (token->token_type == ENVP)
		res = handle_envp(token->t_data, handler, envp_var);
	else if (token->token_type == SPACE)
		res = bind_field(*com, handler);
	else
		res = add_to_word(token->t_data, handler);
	return (res);
}