#include "../../incs/minishell.h"

char	*get_var_value(char *var)
{
	t_list	*iter;
	char	*temp;

	temp = ft_straddchar(var, '=');
	iter = g_envp->envp_list;
	if (g_envp->envp_list)
	{
		while (iter != NULL)
		{
			if (ft_strbegins(iter->content, temp))
			{
				free(temp);
				return (ft_strchr(iter->content, '=') + 1);
			}
			iter = iter -> next;
		}
	}
	free(temp);
	return (NULL);
}
