/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:06:38 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/03 20:28:04 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	check_for_error(char *msg, int pred)
{
	if (pred)
	{
		ft_print_error_errno(SHELL_NAME, msg, NULL);
		return (ERROR);
	}
	return (SUCCESS);
}
