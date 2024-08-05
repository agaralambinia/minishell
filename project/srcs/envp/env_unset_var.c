/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:16:40 by defimova          #+#    #+#             */
/*   Updated: 2024/08/03 18:26:18 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	env_unset_var(char *name, t_envp *envp_var)
{
	char	*env_var;
	char	*temp;
	int		res;

	if (!is_in_env_list(name, &(envp_var->envp_list)))
		return (ERROR);
	if (!ft_strcmp(name, "SHLVL"))
		return (0);
	env_var = get_envp_list_val(name, &envp_var->envp_list);
	if (env_var)
	{
		temp = ft_strjoin(name, "=");
		env_var = ft_strjoin(temp, env_var);
		free(temp);
		res = ft_list_remove(env_var, &(envp_var->envp_list));
		free(env_var);
	}
	else
		res = ft_list_remove(name, &(envp_var->envp_list));
	return (res);
}
