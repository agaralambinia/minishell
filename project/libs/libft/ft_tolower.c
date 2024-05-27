/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:11:29 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:48:20 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((unsigned char)c >= 65 && (unsigned char)c <= 90)
		return (c + 32);
	return (c);
}
/*
Используется для преобразования алфавита в нижний регистр
*/
/*
#include <stdio.h>
int	main()
{
	printf("z %c\n", ft_tolower('z'));
	printf("a %c\n", ft_tolower('a'));
	printf("z %c\n", ft_tolower('Z'));
	printf("a %c\n", ft_tolower('A'));
	printf("1 %c\n", ft_tolower('1'));
}
*/
