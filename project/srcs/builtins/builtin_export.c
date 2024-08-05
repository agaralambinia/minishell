/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:44 by defimova          #+#    #+#             */
/*   Updated: 2024/08/02 19:52:07by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static bool	is_valid_arg(char *arg)
{
	int	index;

	if (arg[0] == '\0' || arg[0] == '=' || ft_isdigit(arg[0]))
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '=' && (ft_isalnum(arg[index])
			|| arg[index] == '_' || (arg[index] == '+' && arg[index + 1] != '\0'
				&& arg[index + 1] == '=')))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}

static int	env_putvar_ex(char *name, char *str, t_envp *envp_var, bool plus)
{
	char	*old_var;
	char	*temp_name;
	char	*cur_val;

	if (str)
	{
		temp_name = ft_strjoin(name, "=");
		cur_val = get_envp_list_val(name, &envp_var->envp_list);
		if (!cur_val)
			old_var = ft_strdup(name);
		else
			old_var = ft_strjoin(temp_name, cur_val);
		if (!plus)
			ft_list_replace(envp_var, old_var, ft_strjoin(temp_name, str));
		else
			ft_list_replace(envp_var, old_var, ft_strjoin(old_var, str));
		free(temp_name);
		free(old_var);
	}
	else if (!is_in_env_list(name, &(envp_var->envp_list)))
		ft_list_replace(envp_var, NULL, name);
	else
		free(name);
	return (SUCCESS);
}

static int	export_put_var(char *arg, t_envp *envp_var)
{
	int		i;
	char	*name;
	int		exit_status;

	i = 0;
	exit_status = SUCCESS;
	while (arg[i] != '=' && arg[i] != '+' && arg[i])
		i++;
	name = (char *)safe_malloc(sizeof(char) * (i + 1));
	ft_strncpy(name, arg, i);
	if (arg[i] == '=')
		exit_status = env_putvar_ex(name, ft_strchr(arg, '=') + 1, envp_var,
				false);
	else if (arg[i] == '+')
		exit_status = env_putvar_ex(name, ft_strchr(arg, '=') + 1, envp_var,
				true);
	else
		return (env_putvar_ex(name, NULL, envp_var, false));
	free(name);
	return (exit_status);
}

static void	handle_invalid_arg(char *arg)
{
	char	*err_name;
	char	*err_arg;

	err_name = ft_strjoin("`", arg);
	err_arg = ft_strjoin(err_name, "\'");
	free(err_name);
	ft_print_error(SHELL_NAME, "export", err_arg, "not a valid identifier");
	free(err_arg);
}

int	builtin_export(int argc, char **argv, t_envp *envp_var, t_cmd *cmd)
{
	int	exit_status;
	int	index;
	int	fd;

	fd = handle_redirs(cmd);
	if (fd < 0)
		return (EXIT_FAILURE);
	exit_status = SUCCESS;
	if (argc == 1)
		print_environment_vars(envp_var, fd);
	if (fd > 2)
		close(fd);
	index = 0;
	while (argc > 1 && argv[++index])
	{
		if (is_valid_arg(argv[index]) == false)
		{
			handle_invalid_arg(argv[index]);
			exit_status = ERROR;
		}
		else
			exit_status = export_put_var(argv[index], envp_var);
	}
	return (exit_status);
}
