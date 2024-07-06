/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:28 by defimova          #+#    #+#             */
/*   Updated: 2024/07/05 20:55:30 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_env(int argc __attribute((unused)),
	char **argv __attribute((unused)), t_envp *envp_var)
{
	t_list	*iter;

	if (envp_var->envp_list == NULL)
	{
		ft_print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (ERROR);
	}
	iter = (t_list *)safe_malloc(sizeof(t_list));
	iter = envp_var->envp_list;
	while (iter != NULL)
	{
		ft_putendl_fd(iter -> content, STDOUT_FILENO);
		iter = iter -> next;
	}
	return (SUCCESS);
}