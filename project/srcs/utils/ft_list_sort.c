/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:13 by defimova          #+#    #+#             */
/*   Updated: 2024/07/06 18:18:14 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	swap(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || (*lst)->next == NULL)
		return ;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->dt = (*lst)->dt;
	(*lst)->dt = (*lst)->next->dt;
	(*lst)->next->dt = temp->dt;
	free(temp);
}

void	ft_list_sort(t_list *lst)
{
	int		i;
	int		j;
	t_list	*iter;
	int		len;

	i = 0;
	j = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		j = 0;
		iter = lst;
		while (j < len - i - 1)
		{
			if (ft_strcmp(iter -> dt, iter -> next -> dt) > 0)
				swap(&iter);
			j++;
			iter = iter -> next;
		}
		i++;
	}
}
