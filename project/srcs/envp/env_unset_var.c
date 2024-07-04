#include "../../incs/minishell.h"

int env_unset_var(char *name, t_envp *envp_var)
{
    char *env_var;
    
    env_var = env_find_var(name);
    if (env_var == NULL)
        return (ERROR);
    return (ft_list_remove(env_var, envp_var->envp_list));
}