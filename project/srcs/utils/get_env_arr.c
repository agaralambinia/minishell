/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:36:14 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/05 11:36:40 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	**get_env_arr(void)
{
	char	**arr;
	int		len;
	int		i;
	t_list	*tmp;

	len = ft_lstsize(g_envp->envp_list);
	len++;
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	tmp = g_envp->envp_list;
	while (i < len)
	{
		arr[i] = (char *)(tmp->dt);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}
