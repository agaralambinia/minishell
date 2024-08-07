/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:28 by defimova          #+#    #+#             */
/*   Updated: 2024/08/02 19:11:40 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_env(t_envp *envp_var, t_cmd *cmd)
{
	t_list	*iter;
	int		fd;

	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (envp_var->envp_list == NULL)
	{
		ft_print_error(SHELL_NAME, "env", NULL, "environ not set");
		if (fd > 2)
			close(fd);
		return (ERROR);
	}
	iter = envp_var->envp_list;
	while (iter != NULL)
	{
		if (ft_strcmp("OLDPWD", iter->dt))
			ft_putendl_fd(iter->dt, fd);
		iter = iter->next;
	}
	if (fd > 2)
		close(fd);
	return (SUCCESS);
}
