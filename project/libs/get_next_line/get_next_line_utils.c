/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:34:05 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/03 17:27:29 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	cnt;

	if (dstsize == 0)
		return (ft_strlen(src));
	cnt = 0;
	while (cnt < dstsize - 1 && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	dstlen;

	if (dstsize == 0)
		return (dstsize + ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	dst += dstlen;
	cnt = 0;
	while (cnt < (dstsize - dstlen - 1) && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = 0;
	return (dstlen + ft_strlen(src));
}
*/
char	*ft_strjoin_f1(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	free(s1);
	return (res);
}

/*
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
*/
