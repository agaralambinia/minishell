/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:39:00 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/27 19:39:05 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	get_exit(int exit_info, bool is_fork_ov)
{
	if (is_fork_ov)
	{
		printf("minishell: fork: Resource temporarily unavailable\n");
		return (1);
	}
	if (WIFEXITED(exit_info))
		return (WEXITSTATUS(exit_info));
	else if (WTERMSIG(exit_info) == 2)
		return (130);
	else if (WTERMSIG(exit_info) == 3)
	{
		printf("Quit: 3\n");
		return (131);
	}
	return (0);
}
