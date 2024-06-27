/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_list_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:30:16 by defimova          #+#    #+#             */
/*   Updated: 2024/06/06 20:30:19 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_envp_list_val(char *var, t_envp *envp_var)
{
	t_list	*iter;
	char	*temp;

	temp = ft_straddchar(var, '=');
	iter = envp_var->envp_list;
	if (envp_var->envp_list)
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
