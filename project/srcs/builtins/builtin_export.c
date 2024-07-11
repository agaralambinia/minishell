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

	if (arg[0] == '\0' || arg[0] == '=' || ft_isdigit(arg[0]))
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '='
		&& (ft_isalnum(arg[index]) || arg[index] == '_'))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}

static int env_put_var_export(char *name, char *str, t_envp *envp_var)
{
    char *old_var;

    printf("DEBUG %s %d\n", __FILE__, __LINE__);
    if (str == NULL)
        return (ERROR);
    printf("DEBUG %s %d\n", __FILE__, __LINE__);
    if (str == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    printf("DEBUG %s %d %s\n", __FILE__, __LINE__, get_env_val(ft_strjoin(name, "="), envp_var));
    printf("DEBUG %s %d %s\n", __FILE__, __LINE__, name);
    old_var = ft_strjoin(ft_strjoin(name, "="), get_env_val(name, envp_var));
    printf("DEBUG %s %d NEW=%s OLD=%s\n", __FILE__, __LINE__, ft_strjoin(ft_strjoin(name, "="), str), old_var);
    ft_list_replace(envp_var, old_var, ft_strjoin(ft_strjoin(name, "="), str));
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
	while (arg[i] != '=')
		i++;
	name = (char *)safe_malloc(sizeof(char) * (i + 1));
	name = ft_strncpy(name, arg, i);
	printf("DEBUG %s %d %s %s\n", __FILE__, __LINE__, name, ft_strchr(arg, '=') + 1);
	exit_status = env_put_var_export(name, ft_strchr(arg, '=') + 1, envp_var);
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
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	while (argc > 1 && argv[index])
	{
		if (is_valid_arg(argv[index]) == false)
		{
			printf("DEBUG %s %d %s\n", __FILE__, __LINE__, argv[index]);
			ft_print_error(SHELL_NAME,
				"export", ft_strjoin(ft_strjoin("`", argv[index]), "\'"), "not a valid identifier");
			exit_status = ERROR;
		}
		else if (ft_strchr(argv[index], '='))
		{
			printf("DEBUG %s %d %s\n", __FILE__, __LINE__, argv[index]);
			exit_status = export_put_var(argv[index], envp_var);
		}
		index++;
	}
	return (exit_status);
}
