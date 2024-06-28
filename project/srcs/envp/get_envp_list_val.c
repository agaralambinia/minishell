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

char	*get_envp_list_val(char *var, t_list **envp_list)
{
	t_list	*iter;
	char	*temp;

	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	iter = (t_list *)safe_malloc(sizeof(t_list));
	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	temp = ft_straddchar(var, '=');
	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	iter = *envp_list;
	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	if (envp_list)
	{
		printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
		while (iter != NULL)
		{
			if (ft_strbegins(iter->content, temp))
			{
				printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
				free(temp);
				return (ft_strchr(iter->content, '=') + 1);
			}
			iter = iter -> next;
			printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
		}
	}
	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	free(temp);
	return (NULL);
}
