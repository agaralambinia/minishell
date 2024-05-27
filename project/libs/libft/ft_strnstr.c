/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:23:41 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:44:44 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if ((!haystack && !len) || !len)
		return (NULL);
	i = -1;
	k = ft_strlen(needle) - 1;
	while (haystack[++i] != '\0' && len-- - k)
	{
		if (!ft_strncmp(haystack + i, needle, k + 1))
			return ((char *)(haystack + i));
	}
	return (0);
}
/*
Аргументы:
haystack – указатель на строку, в которой ведется поиск.
needle – указатель на искомую строку.
len - максимальная длина строки, в которой ведется поиск.

Возвращаемое значение:
NULL – если строка needle не входит в строку needle.
Указатель на первое вхождение строки needle в строку haystack.

Описание:

Функция ft_strnstr ищет первое вхождение строки (за исключением признак конца
строки), на которую указывает аргумент needle, в строку , на которую указывает
аргумент haystack. Если строка needle имеет нулевую длину, то функция вернет
указатель на начало строки haystack.
*/

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char *s1 = "AAAAAAAAAAAAA";
	size_t max = strlen(s1);

	char *i1 = strnstr(s1, s1, max);
	char *i2 = ft_strnstr(s1, s1, max);
	printf("%s\n", i1);
	printf("%s\n", i2);
	//printf("%s\n", ft_strnstr(NULL, "fake", 3));
	ft_strnstr("fake", NULL, 3);
	char haystack[30] = "aaabcabcd";
	printf("%d\n", ft_strnstr(haystack, "aabc", 10) == haystack + 1);
	printf("%d\n", ft_strnstr(haystack, "aabc", 0) == 0);
	printf("%d\n", ft_strnstr(haystack, "aaabc", 5) == haystack);
	printf("%d\n", ft_strnstr(haystack, "abcd", 9) == haystack + 5);
	printf("%d\n", ft_strnstr("1", "a", 1) == NULL);
}
*/
