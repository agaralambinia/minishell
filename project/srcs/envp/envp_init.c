#include "../../incs/minishell.h"

void	envp_init(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_envp = (char **)safe_malloc(sizeof(char *) * i);
	i = -1;
	while (envp[++i])
		g_envp[i] = ft_strdup(envp[i]);
}
