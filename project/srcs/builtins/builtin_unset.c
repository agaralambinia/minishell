/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:56:09 by defimova          #+#    #+#             */
/*   Updated: 2024/07/11 16:16:06 by sosokin          ###   ########.fr       */
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

int	builtin_unset(char **argv, t_envp *envp_var)
{
	int		exit_status;
	int		arg_index;
	int		char_index;
	char	*err;

	exit_status = SUCCESS;
	arg_index = 0;
	while (argv[++arg_index])
	{
		char_index = 0;
		while (argv[arg_index][char_index] && (ft_isalnum(argv[arg_index]
				[char_index]) || argv[arg_index][char_index] == '_'))
			char_index++;
		if (argv[arg_index][char_index] != '\0' || argv[arg_index][0] == '\0')
		{
			err = get_err(argv[arg_index]);
			ft_print_error(SHELL_NAME, "unset", err, "not a valid identifier");
			free(err);
			exit_status = ERROR;
		}
		else
			env_unset_var(argv[arg_index], envp_var);
	}
	return (exit_status);
}
