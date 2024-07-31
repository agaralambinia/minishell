/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_env_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:55:26 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/31 17:55:29 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

bool	is_in_env_list(char *name, t_list **envp_list)
{
	t_list	*iter;

	iter = *envp_list;
	if (envp_list)
	{
		while (iter != NULL)
		{
			if (ft_strbegins(iter->dt, name))
				return (true);
			iter = iter->next;
		}
	}
	return (false);
}
