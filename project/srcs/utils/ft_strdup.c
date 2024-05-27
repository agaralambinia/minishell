#include "../../incs/minishell.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	p = (char *) safe_malloc((ft_strlen(src) + 1) * sizeof(char));
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}