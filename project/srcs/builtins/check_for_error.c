/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:06:38 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/01 22:19:55 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	check_for_error(char *msg, int pred)
{
	if (pred)
	{
		perror(msg);
		return (ERROR);
	}
	return (SUCCESS);
}
