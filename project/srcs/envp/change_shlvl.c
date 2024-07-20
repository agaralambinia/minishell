#include "../../incs/minishell.h"

int	change_shlvl(t_envp *envp_var, int val)
{
	int		res;
	int		shlvl;
	char	*shlvl_s;

	shlvl = envp_var->shlvl + val;
	shlvl_s = ft_itoa(shlvl);
	envp_var->shlvl = shlvl;
	res = env_set_env("SHLVL", shlvl_s, envp_var);
	free (shlvl_s);
	return (res);
}