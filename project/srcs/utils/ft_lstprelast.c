/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprelast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:25:49 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 23:25:50 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_list	*ft_lstprelast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (lst == NULL)
		return (lst);
	while (last->next != NULL && last->next->next != NULL)
		last = last->next;
	return (last);
}
