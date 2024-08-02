/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:02 by defimova          #+#    #+#             */
/*   Updated: 2024/08/02 19:11:18 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	check_for_n_arg(char *str)
{
	int	i;

	i = 2;
	while (str[i])
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
			break ;
	}
	return (include_newline);
}

int	builtin_echo(char **argv, t_cmd *cmd)
{
	int		index;
	bool	include_newline;
	int		fd;

	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	include_newline = check_for_newline(argv, &index);
	while (argv[index])
	{
		ft_putstr_fd(argv[index], fd);
		if (argv[index + 1])
			ft_putstr_fd(" ", fd);
		index++;
	}
	if (include_newline)
		ft_putstr_fd("\n", fd);
	if (fd > 2)
		close(fd);
	return (SUCCESS);
}
