/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:02 by defimova          #+#    #+#             */
/*   Updated: 2024/07/12 17:21:57 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	check_for_n_arg(char *str)
{
	int		i;

	i = 2;
	while(str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_for_newline(char **argv, int *index)
{
	bool	include_newline;

	include_newline = true;
	*index = 1;
	while (argv[*index])
	{
		if (ft_strbegins(argv[*index], "-n") && check_for_n_arg(argv[*index]))
		{
			include_newline = false;
			(*index)++;
		}
		else
			break;
	}	
	return (include_newline);
}

int	builtin_echo(char **argv)
{
	int		index;
	bool	include_newline;

	include_newline = check_for_newline(argv, &index);
	while (argv[index])
	{
		ft_putstr_fd(argv[index], 1);
		if (argv[index + 1])
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (include_newline)
		ft_putchar_fd('\n', 1);
	return (SUCCESS);
}
