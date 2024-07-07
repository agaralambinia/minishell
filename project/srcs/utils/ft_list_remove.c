/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:32 by defimova          #+#    #+#             */
/*   Updated: 2024/07/06 18:18:33 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_list_remove(char *env_var, t_list *envp_list)
{
	t_list	*temp;
	t_list	*temptwo;

	temp = envp_list;
	while ((ft_strcmp(temp->content, env_var) != 0) && temp != NULL)
		temp = temp -> next;
	if (temp == NULL)
		return (SUCCESS);
	temptwo = temp -> next;
	temp -> next = temptwo -> next;
	return (SUCCESS);
}
