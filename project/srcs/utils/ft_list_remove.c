/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:32 by defimova          #+#    #+#             */
/*   Updated: 2024/07/11 17:28:27 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_list_remove(char *env_var, t_list **envp_list)
{
	t_list	*temp;
	t_list	*todel;

	temp = *envp_list;
	if (ft_strcmp(temp->content, env_var) == 0)
	{
		envp_list = &(temp->next);
		ft_lstdelone(temp, &free);
		return (SUCCESS);
	}
	while (temp->next != NULL && ft_strcmp(temp->next->content, env_var) != 0)
		temp = temp -> next;
	if (temp->next == NULL)
		return (SUCCESS);
	todel = temp->next;
	temp->next = todel->next;
	ft_lstdelone(todel, &free);
	return (SUCCESS);
}
