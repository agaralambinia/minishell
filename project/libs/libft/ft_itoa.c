/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:02:27 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 07:22:10 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int		len;
	long	nlong;

	nlong = n;
	if (n == 0)
		return (1);
	len = 0;
	if (nlong < 0)
	{
		len++;
		nlong *= -1;
	}
	while (nlong)
	{
		len++;
		nlong /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nbr;

	if (n == -2147483648)
		nbr = 2147483648;
	else if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	len = ft_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n == 0)
		res[0] = 48;
	if (n < 0)
		res[0] = 45;
	return (res);
}
/*
Аргументы:
n – число которое нужно конвертировать

Возвращаемое значение:
NULL – если не удалость выделить память
Строка, отображающее число

Описание:
Выделяет память и возвращает строку, представляющую целое число,
полученное в качестве аргумента.
Обрабатывает отрицательные числа.
*/
/*
#include <stdio.h>
#include <limits.h>
int main()
{
	printf("%s\n", ft_itoa(-300));
	printf("%s\n", ft_itoa(300));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(0));
}
*/
