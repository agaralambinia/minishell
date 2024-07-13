/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:55:44 by defimova          #+#    #+#             */
/*   Updated: 2024/07/07 17:11:54 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	print_environment_vars(t_envp *envp_var)
{
	t_list	*env_copy;
	char	*temp;
	int		i;

	if (envp_var == NULL)
		return ;
	env_copy = (t_list *)malloc(sizeof(t_list));
	if (env_copy == NULL)
	{
		ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
		return ;
	}
	env_copy = envp_var->envp_list;
	ft_list_sort(env_copy);
	while (env_copy != NULL)
	{
		i = 0;
		while (((char *)env_copy->content)[i] != '=')
			i++;
		temp = (char *)safe_malloc(sizeof(char) * (i + 1));
		temp = ft_strncpy(temp, env_copy->content, i + 1);
		printf("declare -x %s\"%s\"\n", temp, (
			ft_strchr(env_copy->content, '=') + 1));
		env_copy = env_copy -> next;
		free (temp);
	}
}

static bool	is_valid_arg(char *arg)
{
	int	index;

	if (arg[0] == '\0' || arg[0] == '=' || ft_isdigit(arg[0]))
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '=' &&
		(ft_isalnum(arg[index]) || arg[index] == '_' ||
		(arg[index] == '+' && arg[index + 1] != '\0' &&
		arg[index + 1] == '=')))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}

static int env_put_var_export(char *name, char *str, t_envp *envp_var, bool plus)
{
    char *old_var;

    if (str == NULL)
        return (ERROR);
    if (str == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    old_var = ft_strjoin(ft_strjoin(name, "="), get_envp_list_val(name, &envp_var->envp_list));
	if (!plus)
    	ft_list_replace(envp_var, old_var, ft_strjoin(ft_strjoin(name, "="), str));
	else
		ft_list_replace(envp_var, old_var, ft_strjoin(old_var, str));
	free(old_var);
    return (SUCCESS);
}

static int	export_put_var(char *arg, t_envp *envp_var)
{
	int		i;
	char	*name;
	int		exit_status;

	i = 0;
	exit_status = SUCCESS;
	while (arg[i] != '=' && arg[i] != '+')
		i++;
	name = (char *)safe_malloc(sizeof(char) * (i + 1));
	name = ft_strncpy(name, arg, i);
	if (arg[i] == '=')
		exit_status = env_put_var_export(name, ft_strchr(arg, '=') + 1,
			envp_var, false);
	else
		exit_status = env_put_var_export(name, ft_strchr(arg, '=') + 1,
			envp_var, true);
	free (name);
	return (exit_status);
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
				"export", ft_strjoin(ft_strjoin("`", argv[index]), "\'"),
				"not a valid identifier");
			exit_status = ERROR;
		}
		else if (ft_strchr(argv[index], '='))
		{
			exit_status = export_put_var(argv[index], envp_var);
		}
		index++;
	}
	return (exit_status);
}
