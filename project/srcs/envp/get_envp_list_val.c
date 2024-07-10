/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_list_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:30:16 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 16:38:17 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_envp_list_val(char *var, t_list **envp_list)
{
	t_list	*iter;
	char	*temp;
	char	eq[2];

	eq[0] = '=';
	temp = ft_strjoin(var, "=");
	iter = *envp_list;
	if (envp_list)
	{
		while (iter != NULL)
		{
			if (ft_strbegins(iter->content, temp))
			{
				free(temp);
				return (ft_strchr(iter->content, '=') + 1);
			}
			iter = iter -> next;
		}
	}
	free(temp);
	return (NULL);
}
