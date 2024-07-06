/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:02 by defimova          #+#    #+#             */
/*   Updated: 2024/07/06 17:22:29 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	builtin_echo(char **argv)
{
	int		index;
	bool	include_newline;

	include_newline = false;
	index = 1;
	while (argv[index] && !ft_strncmp(argv[index], "-n", 3))
		index++;
	if (index == 1)
		include_newline = true;
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
