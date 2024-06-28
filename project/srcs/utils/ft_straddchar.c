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

	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	if (!c)
		return (NULL);
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	if (!str)
	{
		printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
		result = (char *)safe_malloc(2 * sizeof(char));
		result[0] = c;
		return (result);
	}
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	strlen = ft_strlen(str);
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	result = (char *)safe_malloc((strlen + 2) * sizeof(char));
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	i = -1;
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	while (++i < strlen)
		*(result + i) = *(str + i);
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	*(result + i) = c;
	printf(RED"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	return (result);
}
