/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_clean_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:23:09 by defimova          #+#    #+#             */
/*   Updated: 2024/07/21 19:23:12 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void create_node(t_list *i) 
{
	t_list	*temp;

	temp = (t_list *)safe_malloc(sizeof(t_list));
	temp->dt = (i->next->next)->dt;
	temp->next = (i->next->next)->next;
	ft_lstdelone(i->next, &free);
	i->next = temp;
}


void	tn_clean_null(t_list **lst)
{
	t_list	*i;

	i = *lst;
	while (i != NULL)
	{
		if (i->next != NULL && i->next->dt != NULL
			&& ((t_tn *)(i->next->dt))->data == NULL)
		{
			if ((i->next)->next != NULL && (i->next->next)->dt != NULL
				&& (i->next->next)->next != NULL)
				create_node(i);
			else
			{
				ft_lstdelone(i->next, &free);
				i->next = NULL;
			}
		}
		i = i -> next;
	}
}
