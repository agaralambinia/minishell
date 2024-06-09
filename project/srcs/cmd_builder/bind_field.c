/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:46:48 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/08 16:41:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	setinout(t_cmd *com, char *word, char *field)
{
	t_list	*node;
	t_redir	*redir;
	
	redir = (t_redir *)safe_malloc(sizeof(t_redir));
	redir->path = word;
	if (field[2])
		redir->mode = 1;
	node = ft_lstnew(redir);
	if (field[1] == 'i')
		ft_lstadd_back(&(com->redir_in), node);
	else if (field[1] == 'o')
		ft_lstadd_back(&(com->redir_out), node);
	field[1] = 0;
	field[2] = 0;
}

void	bind_field(t_cmd *com, char *word, char *field)
{
	t_list	*arg;

	if (field[1])
		setinout(com, word, field);
	else
	{
		if (field[0] == 'c')
		{
			com->command = word;
			field[0] = 'a';
		}
		else if (field[0] == 'a')
		{
			arg = ft_lstnew(word);
			ft_lstadd_back(&(com->args), arg);
		}
	}
}
