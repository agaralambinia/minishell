/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:56:09 by defimova          #+#    #+#             */
/*   Updated: 2024/08/10 13:06:09 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*get_err(char *arg)
{
	char	*err_name;
	char	*res;

	err_name = ft_strjoin("`", arg);
	res = ft_strjoin(err_name, "\'");
	free(err_name);
	return (res);
}

static int	mock_redirs(t_cmd *cmd)
{
	int	fd;

	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (fd > 2)
		close(fd);
	return (0);
}

static int	handle_invalid_arg(char *arg)
{
	char	*err;

	err = get_err(arg);
	ft_print_error(SHELL_NAME, "unset", err, "not a valid identifier");
	free(err);
	return (ERROR);
}

int	builtin_unset(char **argv, t_envp *envp_var, t_cmd *cmd)
{
	int		exit_status;
	int		arg_index;
	int		char_index;

	if (mock_redirs(cmd))
		return (EXIT_FAILURE);
	exit_status = SUCCESS;
	arg_index = 0;
	while (argv[++arg_index])
	{
		char_index = 0;
		while (argv[arg_index][char_index]
			&& (ft_isalnum(argv[arg_index][char_index])
				|| argv[arg_index][char_index] == '_'))
			char_index++;
		if (argv[arg_index][char_index] != '\0' || argv[arg_index][0] == '\0')
			exit_status = handle_invalid_arg(argv[arg_index]);
		else
			env_unset_var(argv[arg_index], envp_var);
	}
	return (exit_status);
}
