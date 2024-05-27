/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:44:58 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 18:48:09 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n--)
	{
		*d = 0;
		d++;
	}
}
/*
Устанавливает первые n байтов области, начинающейся с s в нули (пустые байты).
*/
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char tab[100];
	memset(tab, 'A', 10);
	ft_bzero(tab, 0);
	printf("%s\n", tab);
	char tab2[100];
	memset(tab2, 'A', 15);
	ft_bzero(tab2, 10);
	printf("%s\n", tab2);
	printf("%c\n", tab2[2]);
	printf("%c\n", tab2[14]);
}
*/