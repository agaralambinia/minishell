/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:35:16 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/11 21:24:09 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_env_val(char *envvar, t_envp *envp_var)
{
	t_list		*tmp;
	char		*eqptr;

	if (!*(envvar + 1))
		return ("$");
	tmp = envp_var->envp_list;
	while (tmp)
	{
		if (ft_strbegins(tmp->dt, envvar + 1))
		{
			eqptr = ft_strchr(tmp->dt, '=');
			if (eqptr)
				return (eqptr + 1);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
