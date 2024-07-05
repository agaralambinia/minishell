/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:44 by defimova          #+#    #+#             */
/*   Updated: 2024/07/05 20:55:45 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	print_environment_vars(t_envp *envp_var)
{
	t_list	*env_copy;
	int		var_name_len;

	if (envp_var == NULL)
		return ;
	env_copy = (t_list *)malloc(sizeof(t_list));
	if (env_copy == NULL)
	{
		ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
		return ;
	}
	env_copy = envp_var->envp_list;
	ft_list_insert_sort(env_copy);
	while (env_copy != NULL)
	{
		var_name_len = ft_strlen(ft_strchr(env_copy->content, '='));
		printf("%.*s", var_name_len + 1, (char *)env_copy->content);
		printf("\"%s\"\n", get_envp_list_val(
				env_copy->content, &(envp_var->envp_list)));
		env_copy = env_copy -> next;
	}
}

static bool	is_valid_arg(char *arg)
{
	int	index;

	if (arg[0] == '\0' || arg[0] == '=')
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '='
		&& env_is_var_char(arg[index]))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}

int	builtin_export(int argc, char **argv, t_envp *envp_var)
{
	int	exit_status;
	int	index;

	exit_status = SUCCESS;
	if (argc == 1)
		print_environment_vars(envp_var);
	index = 1;
	while (argc > 1 && argv[index])
	{
		if (is_valid_arg(argv[index]) == false)
		{
			ft_print_error(SHELL_NAME,
				argv[index], NULL, "not a valid identifier");
			exit_status = ERROR;
		}
		else if (ft_strchr(argv[index], '='))
			env_put_var(argv[index], envp_var);
		index++;
	}
	return (exit_status);
}
