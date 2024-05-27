/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:18:44 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:34:52 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/*
   Аргументы:
lst: Адрес ноды для удаления
f: Адрес функции для удаления

Возвращаемое значение: нет

Описание:
Принимает в качестве параметра узел и освобождает память от
содержимого узла, используя функцию ’del’, указанную
в качестве параметра, и освобождает узел.
Память ’next’ не освобождается.
*/
