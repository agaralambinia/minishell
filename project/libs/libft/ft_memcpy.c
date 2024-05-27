/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:48:31 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 18:52:12 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	i = 0;
	if (!src && !dst)
		return (dst);
	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		i++;
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
Функция memcpy копирует n байт из массива (области памяти),
на который указывает аргумент src, в массив (область памяти),
на который указывает аргумент dst.
Если массивы перекрываются, результат копирования будет не определен.
*/
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char dst[100];
	memset(dst, 'A', 10);
	ft_memcpy(dst, "qqqqq", 0);
	printf("A %c\n", dst[0]);
	ft_memcpy(dst, NULL, 0);
	printf("A %c\n", dst[0]);
	char src[15] = {'F', 'F', 'F'};
	ft_memcpy(dst, src, 1);
	printf("FAAAAAAAAA %s\n", dst);
	ft_memcpy(dst, src, 5);
	printf("FFF %s\n", dst);
	ft_memcpy(dst, src, 30);
	printf("FFF %s\n", dst);
}
*/