/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:14:17 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 08:39:41 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	if (!ss1 && !ss2)
		return (0);
	while ((ss1[i] || ss2[i]) && (i < n))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
/*
Аргументы:
s1, s2 – указатели на сравниваемые строки.
size_t n – количество символов для сравнения.

Возвращаемое значение:
0 – если первые n символов сравниваемых строк идентичны.

Положительное число – если в первых n символах сравниваемых строк есть отличия
и код первого отличающегося символа в строке s1 больше кода символа на той же
позиции в строке s2.

Отрицательное число – в первых n символах сравниваемых строк есть отличия
и код первого отличающегося символа в строке s1 меньше кода символа на той же
позиции в строке s2.
*/
/*
#include <stdio.h>
int	main()
{
	char s[] = "ft_strn456";
	char s2[] = "ft_strn789";
	printf("0 %d\n", ft_strncmp(s, s2, 3));
	printf("0 %d\n", ft_strncmp(s, s2, 7));
	printf("-3 %d\n", ft_strncmp(s, s2, 8));
	printf("3 %d\n", ft_strncmp(s2, s, 8));
	printf("-3 %d\n", ft_strncmp(s, s2, 10));
	printf("3 %d\n", ft_strncmp(s2, s, 10));
}
*/
