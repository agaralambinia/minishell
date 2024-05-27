/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:02:26 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:45:31 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	if (!dst && !l)
		return (0);
	while (dst[dst_len] != '\0' && dst_len < l)
		dst_len++;
	i = dst_len;
	while (src[dst_len - i] && dst_len + 1 < l)
	{
		dst[dst_len] = src[dst_len - i];
		dst_len++;
	}
	if (i < l)
		dst[dst_len] = '\0';
	return (i + ft_strlen(src));
}
/*
Используется для объединения символов из src в dst и добавления нулевого
терминатора к результирующей строке.
Функция strlcat возвращает длину объединённой строки, независимо от того,
удалось ли скопировать её полностью.
Это позволяет легко вычислить требуемый размер буфера.
Если dst не является нуль-терминированным, то он не будет модифицирован.
Функция strlcat не будет исследовать более чем l символов буфера dst.
Это помогает избежать переполнения буфера.
Если dst и src являются перекрывающимися буферами, поведение не определено.
*/
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	printf("%d\n", ft_strlcat(dest, src, 0) == strlen(src) &&
	!strcmp(dest, "B"));
	dest[0] = 'B';
	printf("%d\n", ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"));
}
*/
