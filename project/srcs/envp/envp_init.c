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
	int			i;
	long long	res;

	i = -1;
	while(str[++i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')
			|| ((str[i] == '+' || str[i] == '-') && i == 0)))
			return (0);
	}
	i = 0;
	res = ft_atoll_p(str, &i);
	if (i == 1)
	{
		if (res < 0)
			return (INT_MIN);
		else
			return (INT_MAX - 1);
	}
	return ((int)res);
}

static void inc_shlvl_var(char **var)
{
	char	*str;
	int		atoi_res;

	str = ft_strdup(ft_strrchr(*var, '=') + 1);
	atoi_res = shlvl_atoi(str);
	free(str);
	if (atoi_res >= 999)
	{
		printf("minishell: warning: shell level (%d) too high, \
			resetting to 1\n", atoi_res + 1);
		*var = "SHLVL=1";
	}
	else if (atoi_res < 0)
	{
		printf("minishell: warning: shell level (%d) <= 0, resetting to 1\n",
			atoi_res + 1);
		*var = "SHLVL=0";
	}
	else
	{
		str = ft_itoa(atoi_res + 1);
		*var = ft_strjoin("SHLVL=", str);
		free (str);
	}
}

static void	inc_shlvl(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if(!ft_strncmp(envp[i], "SHLVL=", 6))
			inc_shlvl_var(&envp[i]);
	}
}

void	envp_init(char **envp, t_envp **envp_var)
{
	inc_shlvl(envp);
	*envp_var = (t_envp *)safe_malloc(sizeof(t_envp));
	envp_list_init(envp, &(*envp_var)->envp_list);
	//(*envp_var)->token_list = (t_list *)safe_malloc(sizeof(t_list));
	(*envp_var)->last_code = 0;
}
