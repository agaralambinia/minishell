/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:32:34 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/14 15:32:35 by sosokin          ###   ########.fr       */
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
	if ((a == ' ') || (a == '\n') || (a == '\t') || (a == '\v')
		|| (a == '\f') || (a == '\r'))
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

int	print_numeric_error(char *str, t_envp *envp_var)
{
	printf("exit\nminishell: exit: %s numeric argument required\n", str);
	envp_var->last_code = 255;
	return (ERROR);
}

unsigned char	builtin_exit(char **argv, t_envp *envp_var)
{
	int				is_ov;
	unsigned char	exit_code;

	is_ov = 0;
	exit_code = 0;
	envp_var->last_code = 0;
	envp_var->is_exit = true;
	if (arrlen((void **)argv) <= 2)
		printf("exit\n");
	if (arrlen((void **)argv) == 2)
	{
		envp_var->last_code = ft_atoll_p(argv[1], &is_ov);
		if (!is_valid_str(argv[1]) || is_ov)
			exit_code = print_numeric_error(argv[1], envp_var);
	}
	else
	{
		printf("exit\nminishell: exit: too many arguments\n");
		envp_var->is_exit = false;
		exit_code = ERROR;
	}
	return (exit_code);
}
