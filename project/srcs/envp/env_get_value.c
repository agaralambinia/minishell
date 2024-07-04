#include "../../incs/minishell.h"

char *env_get_value(char *name)
{
    char *var = env_find_var(name);
    if (var)
        return ft_strchr(var, '=') + 1;
    return NULL;
}