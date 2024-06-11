/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:48:14 by sosokin           #+#    #+#             */
/*   Updated: 2024/02/03 17:11:27 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*check_reminder(char **rem)
{
	char	*nlp;
	char	*out;
	char	*tmp;

	if (!(*rem))
	{
		*rem = (char *)malloc(sizeof(char));
		if (!*rem)
			return (NULL);
		**rem = '\0';
	}
	else
	{
		nlp = ft_strchr(*rem, '\n');
		if (nlp)
		{
			out = ft_substr(*rem, 0, nlp - *rem + 1);
			tmp = *rem;
			*rem = ft_substr(*rem, nlp - *rem + 1, ft_strlen(nlp + 1));
			free(tmp);
			return (out);
		}
	}
	return (NULL);
}

char	*do_read(int fd, char **rem)
{
	char	buf[BUFFER_SIZE + 1];
	int		rb;
	char	*nlp;
	char	*out;
	char	*tmp;

	rb = read(fd, buf, BUFFER_SIZE);
	while (rb > 0)
	{
		buf[rb] = '\0';
		nlp = ft_strchr(buf, '\n');
		if (!nlp)
			*rem = ft_stradd(*rem, buf);
		else
		{
			tmp = ft_substr(buf, 0, nlp - buf + 1);
			out = ft_stradd(*rem, tmp);
			free(tmp);
			*rem = ft_substr(buf, nlp - buf + 1, BUFFER_SIZE);
			return (out);
		}
		rb = read(fd, buf, BUFFER_SIZE);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*rem[FOPEN_MAX];

	if (fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	out = check_reminder(&rem[fd]);
	if (out)
		return (out);
	out = do_read(fd, &rem[fd]);
	if (out)
		return (out);
	if (ft_strlen(rem[fd]))
	{
		out = rem[fd];
		rem[fd] = NULL;
		return (out);
	}
	free(rem[fd]);
	rem[fd] = NULL;
	return (NULL);
}
