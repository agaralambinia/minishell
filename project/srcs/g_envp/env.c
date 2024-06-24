#include "../../incs/env.h"

char *env_get_value(char *name)
{
    char *var = env_find_var(name);
    if (var)
        return ft_strchr(var, '=') + 1;
    return NULL;
}

bool env_is_var_char(char c)
{
    return (ft_isalnum(c) || c == '_');
}

int env_unset_var(char *name)
{
    char *env_var = env_find_var(name);
    if (env_var == NULL)
        return (ERROR);
    return (split_remove_str(&(g_envp->envp_list), env_var));
}

int env_put_var(char *str)
{
    char *old_var;
    char *new_var;
    int status;

    if (str == NULL || ft_strchr(str, '=') == NULL)
        return (ERROR);

    new_var = ft_strdup(str);
    if (new_var == NULL)
        return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));

    old_var = env_find_var(str);
    status = split_replace_str(&(g_envp->envp_list), old_var, new_var);
    if (status == ERROR)
    {
        status = split_append_str(&(g_envp->envp_list), new_var);
        if (status == ERROR)
        {
            free(new_var);
            return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
        }
    }
    else
    {
        free(new_var);
    }
    return (0);
}

int env_set_env(char *name, char *value)
{
    char *var_str;
    char *tmp;
    int status;

    if (name == NULL || value == NULL)
        return (ERROR);

    tmp = ft_strjoin(name, "=");
    if (tmp == NULL)
        return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));

    var_str = ft_strjoin(tmp, value);
    free(tmp);
    if (var_str == NULL)
        return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));

    status = env_put_var(var_str);
    free(var_str);
    return (status);
}
