/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:34:05 by sosokin           #+#    #+#             */
/*   Updated: 2024/02/03 17:11:43 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*cp;

	cc = (char)c;
	cp = (char *)s;
	while (*cp)
	{
		if (*cp == cc)
			return (cp);
		cp++;
	}
	if (*cp == cc)
		return (cp);
	return (NULL);
}

char	*ft_stradd(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	free(s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			slen;
	char			*res;
	unsigned int	cnt;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	if (len > (slen - start))
		len = slen - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	cnt = 0;
	while (cnt < len)
		res[cnt++] = s[start++];
	res[cnt] = 0;
	return (res);
}
