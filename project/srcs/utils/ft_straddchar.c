/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:25:19 by defimova          #+#    #+#             */
/*   Updated: 2024/06/06 20:25:22 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	*ft_memalloc(size_t size)
{
	char	*this;

	this = malloc(size);
	if (!this)
	{
		ft_putstr_fd("Malloc broken!\n", 1);
		exit(0);
	}
	ft_memset(this, 0, size);
	return (this);
}

static void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

static int	ft_stradd(char **dest, char *src)
{
	char	*temp;

	if (!src)
		return (0);
	if (!(*dest) || *dest == NULL)
	{
		*dest = ft_strdup(src);
		return (1);
	}
	temp = ft_strdup(*dest);
	ft_strdel(dest);
	*dest = ft_strjoin(temp, src);
	ft_strdel(&temp);
	return (1);
}

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(sizeof(char) * (size + 1));
	ft_memset(str, '\0', size + 1);
	return (str);
}

void	ft_straddchar(char **str, char c)
{
	char	*temp;

	temp = ft_strnew(1);
	temp[0] = c;
	//printf("DEBUG <%c> %s\n", c, __FILE__); //TODO убрать
	if (*str == NULL)
		*str = ft_strdup(temp);
	else
		ft_stradd(str, temp);
	ft_strdel(&temp);
}
