#include "../../incs/minishell.h"

int env_set_env(char *name, char *value, t_envp *envp_var)
{
    char *var_str;
    char *tmp;
    int status;

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
