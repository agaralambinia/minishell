/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:15:26 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 23:15:27 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	env_set_env(char *name, char *value, t_envp *envp_var)
{
    char	*var_str;
    char	*tmp;
    int		status;

    if (name == NULL || value == NULL)
        return (ERROR);
    tmp = ft_strjoin(name, "=");
    if (tmp == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    var_str = ft_strjoin(tmp, value);
    if (var_str == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    status = env_put_var(tmp, var_str, envp_var);
    free(tmp);
    return (status);
}
