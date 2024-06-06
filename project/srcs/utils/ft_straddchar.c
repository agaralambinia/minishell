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

char	*ft_straddchar(char *str, char c)
{
	size_t	i;
	size_t	strlen;
	char	*result;

	if (!c)
		return (NULL);
	if (!str)
	{
		result = (char *) safe_malloc(2 * sizeof(char));
		result[0] = c;
		return (result);
	}
	strlen = ft_strlen(str);
	result = (char *) safe_malloc((strlen + 2) * sizeof(char));
	i = -1;
	while (++i < strlen)
		*(result + i) = *(str + i);
	*(result + i) = c;
	return (result);
}
