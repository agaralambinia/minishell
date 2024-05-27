/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:31:06 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 19:33:20 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count && size && count > (2147483647 / size))
		return (NULL);
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
/*
Выделяет блок памяти для массива размером count элементов,
каждый из которых занимает
size байт, и инициализирует все свои биты нулями.
В результате выделяется блок памяти размером count * size байт,
весь блок заполнен нулями.

Параметры функции:
count — количество элементов массива, под который выделяется память;
size — размер одного элемента в байтах.
Возвращаемое значение — указатель на выделенный блок памяти.
Тип данных, на который ссылается указатель, всегда void*,
поэтому его можно привести к желаемому типу данных.

Если функции не удалось выделить требуемый блок памяти,
возвращается нулевой указатель.
*/
/*
#include <stdio.h>
#include <string.h>
#include <limits.h>
int	main()
{
		void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	printf("%d\n", ft_calloc(SIZE_MAX, SIZE_MAX) == NULL);
	printf("%d\n", ft_calloc(INT_MAX, INT_MAX) == NULL);
	printf("%d\n", ft_calloc(INT_MIN, INT_MIN) == NULL);
	p = ft_calloc(0, 0);
	printf("%d\n", p != NULL); free(p);
	p = ft_calloc(0, 5);
	printf("%d\n", p != NULL); free(p);
	p = ft_calloc(5, 0);
	printf("%d\n", p != NULL); free(p);
	p = ft_calloc(-5, -5);
	printf("%d\n", p == NULL); free(p);
}
*/