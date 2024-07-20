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

static int	shlvl_atoi(char *str)
{
	int	i;

	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i])
	}
	
}

static void	inc_shlvl(char **envp)
{
	int		i;
	char	cur_shlvl;
	int		shlvl_atoi_res;

	i = -1;
	while (envp[++i])
	{
		if(!ft_strncmp(envp[i], "SHLVL=", 6))
		{
			cur_shlvl = ft_strrchr(envp[i], '=');
			shlvl_atoi_res = shlvl_atoi(cur_shlvl);
			if (shlvl_atoi_res == 0)
				envp[i] = "SHLVL=1";
			else if (shlvl_atoi_res >= 1000)
			else if (shlvl_atoi_res <= -1000)			
			else if (shlvl_atoi_res < 1)
				envp[i] = "SHLVL=0";
			else
				envp[i] = ft_strjoin(envp[i], ft_itoa(shlvl_atoi_res + 1));
		}
	}
}

void	envp_init(char **envp, t_envp **envp_var)
{
	inc_shlvl(envp);
	*envp_var = (t_envp *)safe_malloc(sizeof(t_envp));
	envp_list_init(envp, &(*envp_var)->envp_list);
	(*envp_var)->token_list = (t_list *)safe_malloc(sizeof(t_list));
	(*envp_var)->last_code = 0;
}
