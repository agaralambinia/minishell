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
	int	index;

	if (g_env == NULL) TODO
	{
		ft_print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (ERROR);
	}
	index = 0;
	while (g_env[index])
	{
		ft_putendl_fd(g_env[index], STDOUT_FILENO);
		index++;
	}
	return (SUCCESS);
}
