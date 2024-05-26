#include "../../incs/minishell.h"

bool	ft_strbegins(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (false);
	return (true);
}