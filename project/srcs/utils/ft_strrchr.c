#include "../../incs/minishell.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = s;
	while (*s)
		s++;
	while (s >= temp)
	{
		if (*s-- == (char)c)
			return ((char *)s + 1);
	}
	return (0);
}