/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:59:55 by defimova          #+#    #+#             */
/*   Updated: 2024/06/22 17:43:22 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	*safe_malloc(size_t str)
{
	void	*result;

	result = malloc(str);
	if (result == NULL)
		ft_exit_error("Error with the malloc");
	ft_bzero(result, str);
	return (result);
}
