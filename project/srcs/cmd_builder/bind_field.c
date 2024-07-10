/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:46:48 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/10 18:28:52 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	setinout(t_cmd *com, t_wordhan *handler)
{
	t_list	*node;
	t_redir	*redir;
	
	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return 0;
	redir->path = handler->word;
	if (handler->is_redir_mode)
		redir->mode = 1;
	node = ft_lstnew(redir);
	if (!node)
		return 0;
	if (handler->redir == 'i')
		ft_lstadd_back(&(com->redir_in), node);
	else if (handler->redir == 'o')
		ft_lstadd_back(&(com->redir_out), node);
	handler->redir = 0;
	handler->is_redir_mode = 0;
	return 1;
}

int	bind_field(t_cmd *com, t_wordhan *handler)
{
	t_list	*arg;
	int		res;

	res = 1;
	if (handler->word)
	{
		if (handler->redir)
			res = setinout(com, handler);
		else
		{
			if (handler->field == 'c')
			{
				com->command = handler->word;
				handler->field = 'a';
			}
			else if (handler->field == 'a')
			{
				arg = ft_lstnew(handler->word);
				res = arg != NULL;
				ft_lstadd_back(&(com->args), arg);
			}
		}
		handler->word = NULL;
	}
	return res;
}
