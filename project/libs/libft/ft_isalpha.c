/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:25:43 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 18:25:46 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int str)
{
	if ((97 <= str && str <= 122) || (65 <= str && str <= 90))
		return (1);
	return (0);
}
/*
Проверяет аргумент, передаваемый через параметр str,
является ли он строчной или прописной буквой алфавита
*/
/*
#include <stdio.h>
int	main()
{
	printf("1 %d\n", ft_isalpha('z'));
	printf("1 %d\n", ft_isalpha('a'));
	printf("1 %d\n", ft_isalpha('Z'));
	printf("1 %d\n", ft_isalpha('A'));
	printf("0 %d\n", ft_isalpha('z' + 1));
	printf("0 %d\n", ft_isalpha('a' - 1));
	printf("0 %d\n", ft_isalpha('Z' + 1));
	printf("0 %d\n", ft_isalpha('A' - 1));
}
*/