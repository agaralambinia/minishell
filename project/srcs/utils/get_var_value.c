#include "../../incs/minishell.h"

char	*get_var_value(char *var)
{
	int		i;
	char	*temp;

	i = -1;
	while (g_envp[++i])
	{
		temp = ft_straddchar(var, '=');
		if (ft_strbegins(g_envp[i], temp))
		{
			free(temp);
			return (ft_strchr(g_envp[i], '=') + 1);
		}
		free(temp);
	}
	return (NULL);
}