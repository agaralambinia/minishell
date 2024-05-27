/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:36:06 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 19:38:24 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
/*
Аргументы:
s – указатель на строку, из которой нужно вытащить подстроку
start - индекс начала подстроки в строке s
len - максимальная длина подстроки

Возвращаемое значение:
NULL – если не удалость выделить память
Указатель подстроку

Описание:
Выделяет и возвращает подстроку из строки ’s’.
Подстрока начинается с индекса ’start’ и имеет максимальный размер ’len’.
*/