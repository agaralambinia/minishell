/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:46:48 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/01 20:55:07 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	setinout(t_command *com, char *word, char *field)
{
	if (field[1] == 'i')
	{
		com->input = word;
		if (field[2])
			com->inmode = 1;
	}
	else if (field[1] == 'o')
	{
		com->output = word; 
		if (field[2])
			com->outmode = 1;
	}
	field[1] = 0;
	field[2] = 0;
}

void	bind_field(t_command *com, char *word, char *field)
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
