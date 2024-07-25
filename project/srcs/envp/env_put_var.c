/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_put_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:12:57 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 23:12:59 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	env_put_var(char *name, char *str, t_envp *envp_var)
{
	char	*old_var;
	char	*old_val;
	char	*tmp;

	if (str == NULL || ft_strchr(str, '=') == NULL)
		return (ERROR);
	if (str == NULL)
	{
		ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
		return (ERROR);
	}
	old_val = get_envp_list_val(name, &envp_var->envp_list);
	if (!old_val)
		old_var = ft_strjoin(name, "");
	else
	{
		tmp = ft_strjoin(name, "=");
		old_var = ft_strjoin(tmp, old_val);
		free(tmp);
	}
	ft_list_replace(envp_var, old_var, str);
	free(old_var);
	return (SUCCESS);
}
