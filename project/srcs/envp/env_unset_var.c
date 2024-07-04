#include "../../incs/minishell.h"

int env_unset_var(char *name, t_envp *envp_var)
{
    char *env_var;
    
    env_var = get_envp_list_val(name, &envp_var->envp_list);
    if (env_var == NULL)
        return (ERROR);
    return (ft_list_remove(env_var, envp_var->envp_list));
}