/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:52:42 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 18:56:18 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (!src && !dst)
		return (dst);
	if (dst > src)
	{
		while (n--)
			ndst[n] = nsrc[n];
	}
	else
	{
		while (n--)
			*ndst++ = *nsrc++;
	}
	return (dst);
}
/*
Аргументы:
dst – указатель на массив в который будут скопированы данные.
src – указатель на массив источник копируемых данных.
n – количество байт для копирования.

Возвращаемое значение:
Функция возвращает указатель на массив, в который скопированы данные.

Описание:
Функция memmove копирует n байт из массива (области памяти),
на который указывает аргумент src, в массив (область памяти),
на который указывает аргумент dst.
При этом массивы (области памяти) могут пересекаться.
*/
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char dst[100];
	memset(dst, 'A', 10);
	ft_memmove(dst, "qqqqq", 0);
	printf("A %c\n", dst[0]);
	ft_memmove(dst, NULL, 0);
	printf("A %c\n", dst[0]);
	char src[15] = {'F', 'F', 'F'};
	ft_memmove(dst, src, 1);
	printf("FAAAAAAAAA %s\n", dst);
	ft_memmove(dst, src, 5);
	printf("FFF %s\n", dst);
	ft_memmove(dst, src, 10);
	printf("FFF %s\n", dst);
	char s[10] = {'1','2','3','4','5','6','7','8','9','0'};
	char sResult[] = {'1','2','3','4','5','6','7','8','9','0'};
	ft_memmove(s, s + 2, 2);
	int i = 0;
	printf("Должно быть 343456 а получилось ");
	while (i <= 5)
	{
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	ft_memmove(sResult + 1, sResult, 2);
	i = 0;
	printf("Должно быть 112456 а получилось ");
	while (i <= 5)
	{
		printf("%c", sResult[i]);
		i++;
	}
	printf("\n");
}
*/