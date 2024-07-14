/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_envp_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:29:32 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 17:34:39 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	envp_list_init(char **envp, t_list **envp_list)
{
	int		i;
	char	*str;

	i = -1;
	while (envp[++i])
	{
		str = ft_strdup(envp[i]);
		ft_lstadd_back(envp_list, ft_lstnew(str));
	}
}

void	envp_init(char **envp, t_envp **envp_var)
{
	*envp_var = (t_envp *)safe_malloc(sizeof(t_envp));
	envp_list_init(envp, &(*envp_var)->envp_list);
	(*envp_var)->token_list = (t_list *)safe_malloc(sizeof(t_list));
	(*envp_var)->last_code = 0;
}
