/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:18:49 by defimova          #+#    #+#             */
/*   Updated: 2024/07/11 17:25:37 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_list_replace(t_envp *envp_var, char *old_var, char *new_var)
{
	t_list	*temp;

	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	temp = envp_var->envp_list;
	if (!old_var)
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		ft_lstadd_back(&(envp_var->envp_list), ft_lstnew(new_var));
		return (SUCCESS);
	}
	while (temp != NULL && ft_strcmp((char *)(temp->content), old_var) != 0)
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		temp = temp -> next;
	}
	if (temp == NULL)
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		ft_lstadd_back(&(envp_var->envp_list), ft_lstnew(new_var));
	}
	else
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		free(temp->content);
		temp->content = new_var;
	}
	return (SUCCESS);
}
