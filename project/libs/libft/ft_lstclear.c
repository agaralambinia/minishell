/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:20:40 by defimova          #+#    #+#             */
/*   Updated: 2024/07/09 20:21:28 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	if (lst && *lst && del)
	{
		elem = *lst;
		while (*lst != NULL)
		{
			elem = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = elem;
		}
		(*lst) = NULL;
	}
}
/*
   Аргументы:
lst: Адрес указателя на узел.
f: Адрес функции для удаления

Возвращаемое значение: нет

Описание:
Удаляет и освобождает данный узел и каждого
преемника этого узла, используя функции ’del’ и free(3).
Указатель на список устанавливается в NULL.
*/
