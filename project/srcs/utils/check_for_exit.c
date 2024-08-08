/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:39:51 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/08 21:46:30 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	check_for_exit(char *cmd, char *arg,  int pred)
{
	if (pred)
	{
		//perror(msg);
		ft_print_error_errno(SHELL_NAME, cmd, arg);
		exit(1);
	}
}
