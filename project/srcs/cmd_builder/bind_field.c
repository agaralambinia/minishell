/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:46:48 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/17 08:12:47 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	setinout(t_cmd *com, t_wordhan *handler)
{
	t_list	*node;
	t_redir	*redir;
	
	redir = (t_redir *)safe_malloc(sizeof(t_redir));
	redir->path = handler->word;
	if (handler->is_redir_mode)
		redir->mode = 1;
	node = ft_lstnew(redir);
	if (handler->redir == 'i')
		ft_lstadd_back(&(com->redir_in), node);
	else if (handler->redir == 'o')
		ft_lstadd_back(&(com->redir_out), node);
	handler->redir = 0;
	handler->is_redir_mode = 0;
}

void	bind_field(t_cmd *com, t_wordhan *handler)
{
	t_list	*arg;

	if (handler->word)
	{
		if (handler->redir)
			setinout(com, handler);
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
				ft_lstadd_back(&(com->args), arg);
			}
		}
		handler->word = NULL;
	}
}
