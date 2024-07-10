/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:59 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 19:24:37 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

//int	builtin_pwd(void)
//{
//	char	path_buffer[PATH_MAX];
//
//	if (getcwd(path_buffer, sizeof(path_buffer)))
//	{
//		ft_putendl_fd(path_buffer, STDOUT_FILENO);
//		return (SUCCESS);
//	}
//	else
//	{
//		ft_print_error_errno(SHELL_NAME, "pwd", NULL);
//		return (ERROR);
//	}
//}

int	builtin_pwd(t_envp *envp_var)
{
	char	path_buffer[PATH_MAX];
	char	*pwd;

	pwd = get_envp_list_val("PWD", &envp_var->envp_list);
	if (!pwd)
	{
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
	else
		printf("%s\n", pwd);
	return (SUCCESS);
}
