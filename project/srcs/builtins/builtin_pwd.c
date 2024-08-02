/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:59 by defimova          #+#    #+#             */
/*   Updated: 2024/08/02 20:15:08 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_pwd(t_envp *envp_var, t_cmd *cmd)
{
	char	path_buffer[PATH_MAX];
	char	*pwd;
	int		fd;
	int		result;

	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	result = SUCCESS;
	pwd = get_envp_list_val("PWD", &envp_var->envp_list);
	if (!pwd)
	{
		if (getcwd(path_buffer, sizeof(path_buffer)))
			ft_putendl_fd(path_buffer, fd);
		else
		{
			ft_print_error_errno(SHELL_NAME, "pwd", NULL);
			result = ERROR;
		}
	}
	else
		ft_putendl_fd(pwd, fd);
	if (fd > 2)
		close(fd);
	return (result);
}
