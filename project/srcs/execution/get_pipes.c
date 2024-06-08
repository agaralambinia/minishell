/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:35:03 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/05 11:32:20 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	**get_pipes(int cmd_cnt)
{
	int	**pp;
	int	i;

	pp = (int **)malloc(sizeof(int *) * (cmd_cnt));
	if (!pp)
		return (NULL);
	i = 0;
	pp[i] = NULL;
	while (i < cmd_cnt - 1)
	{
		pp[i] = (int *)malloc(sizeof(int) * 2);
		if (!(pp[i]))
		{
//			free_arr((void **)pp);
			return (NULL);
		}
		pp[i + 1] = NULL;
		pipe(pp[i]);
		i++;
	}
	return (pp);
}
