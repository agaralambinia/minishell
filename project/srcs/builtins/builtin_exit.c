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
	int i;

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

unsigned char	builtin_exit(char **argv, t_envp *envp_var)
{
	int				arglen;
	char			*mes;
	unsigned char	result;
	char			*err_mes;

	arglen = arrlen((void **)argv);
	mes = "exit\n";
	err_mes = "exit\nminishell: exit:";
	result = 0;
	envp_var->is_exit = true;
	if (arglen == 2)
	{
		if (!is_valid_str(argv[1]))
		{
			printf("%s %s numeric argument required\n", err_mes, argv[1]);
			envp_var->last_code = 255;
			return (ERROR);
		}
		result = ft_atoi(argv[1]);
		envp_var->last_code = result;
	}
	if (arglen > 2)
	{
		printf("%s too many arguments\n", err_mes);
		envp_var->is_exit = false;
		return (ERROR);
	}
	printf("%s", mes);
	return (result);
}
