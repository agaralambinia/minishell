/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_envp_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:29:32 by defimova          #+#    #+#             */
/*   Updated: 2024/06/06 20:29:34 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	envp_list_init(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	i = -1;
	while (envp[++i])
	{
		ft_lstadd_back(&(g_envp->envp_list), ft_lstnew(envp[i]));
	}
}

void	g_envp_init(char **envp)
{
	g_envp = (t_envp *)safe_malloc(sizeof(t_envp *));
	envp_list_init(envp);
	g_envp->token_list = (t_list *)safe_malloc(sizeof(t_list *));
}
