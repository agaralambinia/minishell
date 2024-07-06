/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:59 by defimova          #+#    #+#             */
/*   Updated: 2024/07/05 20:56:00 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_pwd(void)
{
	char	path_buffer[PATH_MAX];

	if (getcwd(path_buffer, sizeof(path_buffer)))
	{
		ft_putendl_fd(path_buffer, STDOUT_FILENO);
		return (SUCCESS);
	}
	else
	{
		ft_print_error_errno(SHELL_NAME, "pwd", NULL);
		return (ERROR);
	}
}
