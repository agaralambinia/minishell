/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:08:31 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:46:14 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((unsigned char)c >= 97 && (unsigned char)c <= 122)
		return (c - 32);
	return (c);
}
/*
Используется для преобразования строчного алфавита в верхний регистр
*/
/*
#include <stdio.h>
int	main()
{
	printf("Z %c\n", ft_toupper('z'));
	printf("A %c\n", ft_toupper('a'));
	printf("Z %c\n", ft_toupper('Z'));
	printf("A %c\n", ft_toupper('A'));
	printf("1 %c\n", ft_toupper('1'));
}
*/
