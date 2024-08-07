/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:33:53 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 18:11:03 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	p = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
Аргументы:
src – указатель на дублируемую строку.

Возвращаемое значение:
NULL – если не удалость выделить память под новую строку или
скопировать строку на которую указывает аргумент str.
Указатель на дублирующую строку.

Описание:
Функция strdup дублирует строку, на которую указывает аргумент str.
Память под дубликат строки выделяется с помощью функции malloc
*/
/*
#include <stdio.h>
#include <string.h>
#include <limits.h>
int	main()
{
	char * s = ft_strdup((char*)"meowmeow");
	int i = 0;
	while (s[i] != '\0')
	{
		printf("%c", s[i]);
		i++;
	}
}
*/
