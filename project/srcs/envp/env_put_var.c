#include "../../incs/minishell.h"

int env_put_var(char *str, t_envp *envp_var)
{
    char *old_var;
    char *new_var;

    if (str == NULL || ft_strchr(str, '=') == NULL)
        return (ERROR);

    new_var = ft_strdup(str);
    if (new_var == NULL)
    {
        print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    old_var = env_find_var(str);
    ft_list_replace(envp_var, old_var, new_var);
    free(new_var);
    return (SUCCESS);
}
