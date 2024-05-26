#include "../../incs/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	if (!ss1 && !ss2)
		return (0);
	while ((ss1[i] || ss2[i]) && (i < n))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}