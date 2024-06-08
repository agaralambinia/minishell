/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipes_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:10:30 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/06 21:26:32 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	setup_pipes_last(int **pp, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(pp[i][0]);
		close(pp[i][1]);
		i++;
	}
	close(pp[i][1]);
	dup2(pp[i][0], 0);
	close(pp[i][0]);
}
