/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:13 by defimova          #+#    #+#             */
/*   Updated: 2024/07/06 18:18:14 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	ft_sort(t_list *newnode, t_list *sorted)
{
	t_list	*cur;

	if (sorted == NULL || sorted->content >= newnode->content)
	{
		newnode->next = sorted;
		sorted = newnode;
	}
	else
	{
		cur = sorted;
		while (cur->next != NULL && cur->next->content < newnode->content)
			cur = cur->next;
		newnode->next = cur->next;
		cur->next = newnode;
	}
}

void	ft_list_insert_sort(t_list *lst)
{
	t_list	*temp;
	t_list	*head;
	t_list	*sorted;

	head = NULL;
	sorted = NULL;
	temp = head;
	while (lst != NULL)
	{
		temp = lst->next;
		ft_sort(lst, sorted);
		lst = temp;
	}
	head = sorted;
}
