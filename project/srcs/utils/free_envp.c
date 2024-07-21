/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:58:00 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/15 20:58:03 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_envp(t_envp *envp_var)
{
	if (envp_var->envp_list && &(envp_var->envp_list))
		ft_lstclear(&(envp_var->envp_list), &free);
	if (envp_var && &(envp_var))
		free(envp_var);
}
