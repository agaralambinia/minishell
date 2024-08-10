/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:32:34 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/10 21:09:07 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	arrlen(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int	isspace_check(const char a)
{
	if ((a == ' ') || (a == '\n') || (a == '\t') || (a == '\v') || (a == '\f')
		|| (a == '\r'))
	{
		return (1);
	}
	else
		return (0);
}

bool	is_valid_str(char *str)
{
	int	i;

	i = 0;
	while (isspace_check(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	print_numeric_error(char *str, t_envp *envp_var, int fd)
{
	if (fd > 2)
		close(fd);
	ft_putendl_fd("exit", STDERR_FILENO);
	ft_print_error(SHELL_NAME, "exit", str, "numeric argument required");
	envp_var->last_code = 255;
}

unsigned char	builtin_exit(char **argv, t_envp *envp_var, t_cmd *cmd)
{
	int	is_ov;
	int	fd;
	
	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	is_ov = 0;
	envp_var->is_exit = true;
	if (argv[1])
	{
		envp_var->last_code = ft_atoll_p(argv[1], &is_ov);
		if (!is_valid_str(argv[1]) || is_ov)
		{
			print_numeric_error(argv[1], envp_var, fd);
			return (envp_var->last_code);
		}
	}
	if (arrlen((void **)argv) > 2)
	{
		ft_print_error(SHELL_NAME, "exit", NULL, "too many arguments");
		envp_var->is_exit = false;
		envp_var->last_code = ERROR;
	}
	return (envp_var->last_code);
}
