/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:44:17 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 10:40:01 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lens(char const *str, char charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*str)
	{
		if (*str != charset && len == 0)
		{
			len = 1;
			i++;
		}
		else if (*str == charset)
			len = 0;
		str++;
	}
	return (i);
}

char	*ft_strc(char *dest, char const *src, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*filline(char const *l, char c, int s)
{
	int		n;
	int		i;
	char	*cur;

	n = 0;
	i = 0;
	while (l[i] == c)
		i++;
	while (n != s)
	{
		if (l[i] == c && !(l[i + 1] == c))
			n++;
		i++;
	}
	n = i;
	while (!(l[n] == c) && (l[n + 1] != '\0') && !(l[n + 1] == c))
		n++;
	cur = (char *)malloc((n - i + 2) * sizeof(char));
	if (!cur)
		return (NULL);
	ft_strc(cur, l, i, n);
	return (cur);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = -1;
	len = lens(s, c);
	result = (char **)malloc((len + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (++i < len)
	{
		result[i] = filline(s, c, i);
		if (!result[i])
		{
			while (--i)
				free(result[i]);
			free(result);
			return (NULL);
		}
	}
	result[i] = NULL;
	return (result);
}
/*
Аргументы:
s – строка которую нужно разбить
c - символ-разделитель

Возвращаемое значение:
NULL – если не удалость выделить память
Массив новых строк

Описание:
Выделяет память и возвращает массив строк, полученный путем разделения
’s’ с использованием символа ’c’ в качестве разделителя.
Массив должен заканчиваться NULL поинтером
*/
/*
#include <stdio.h>
int main()
{	
	char str[] = "aa\0bbb\0kkk\0kkkk";
	char c = '\0';
	int i;
	char **result;

	i = 0;
	result = ft_split(str, c);
	while (*result)
	{
		printf("%s\n", *result);
		result++;
	}
}
*/
