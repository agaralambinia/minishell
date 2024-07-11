#include "../../incs/minishell.h"

int env_unset_var(char *name, t_envp *envp_var)
{
    char	*env_var;
	char	*temp;
	int		res;
    
    env_var = get_envp_list_val(name, &envp_var->envp_list);
	temp = ft_strjoin(name, "=");
	env_var = ft_strjoin(temp, env_var);
	free(temp);
    if (env_var == NULL)
        return (ERROR);
	res = ft_list_remove(env_var, &(envp_var->envp_list));
	free(env_var);
    return (res);
}
