/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:27:05 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 18:28:48 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int str)
{
	if ((97 <= str && str <= 122) || (65 <= str && str <= 90) \
			|| (48 <= str && str <= 57))
		return (1);
	return (0);
}
/*
Проверяет аргумент, передаваемый через параметр str,
является ли он десятичной цифрой или символом алфавита,
прописной или строчной буквой
*/
/*
#include <stdio.h>
int	main()
{
	printf("1 %d\n", ft_isalnum('z'));
	printf("1 %d\n", ft_isalnum('a'));
	printf("1 %d\n", ft_isalnum('Z'));
	printf("1 %d\n", ft_isalnum('A'));
	printf("0 %d\n", ft_isalnum('z' + 1));
	printf("0 %d\n", ft_isalnum('a' - 1));
	printf("0 %d\n", ft_isalnum('Z' + 1));
	printf("0 %d\n", ft_isalnum('A' - 1));
	printf("1 %d\n", ft_isalnum('0'));
	printf("1 %d\n", ft_isalnum('9'));
	printf("0 %d\n", ft_isalnum('9' + 1));
	printf("0 %d\n", ft_isalnum('0' - 1));
}
*/