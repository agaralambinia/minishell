/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:35:05 by defimova          #+#    #+#             */
/*   Updated: 2024/01/26 17:05:00 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*i;

	i = s;
	while (len--)
		*(i++) = (unsigned char)c;
	return (s);
}
/*
Функция заполняет первые len байт области памяти,
на которую указывает аргумент s,
символом, код которого указывается аргументом c.
*/
/*
#include <stdio.h>
int	main()
{
	char tab[100];
	ft_memset(tab, 'A', 10);
	printf("%s\n", tab);
	char tab2[100];
	ft_memset(tab2, 'A', 1);
	printf("%s\n", tab2);
	char tab3[100];
	ft_memset(tab3, 'A', 0);
	printf("%c\n", tab3[0]);
}
*/
