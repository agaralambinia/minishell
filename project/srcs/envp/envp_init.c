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

static void	envp_list_init(char **envp, t_list **envp_list)
{
	int	i;

	i = 0;
	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	//*envp_list = (t_list *)safe_malloc(sizeof(t_list));
	while (envp[i])
		i++;
	i = -1;
	while (envp[++i])
	{
		printf(BLUE"DEBUG %s %d %s\n"RESET, __FILE__, __LINE__, envp[i]);
		ft_lstadd_back(envp_list, ft_lstnew(envp[i]));
	}
}

void	envp_init(char **envp, t_envp **envp_var)
{
	*envp_var = (t_envp *)safe_malloc(sizeof(t_envp));
	envp_list_init(envp, &(*envp_var)->envp_list);
	printf(YELLOW"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	(*envp_var)->token_list = (t_list *)safe_malloc(sizeof(t_list));
}
