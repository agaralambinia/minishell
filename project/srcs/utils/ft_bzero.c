#include "../../incs/minishell.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n--)
	{
		*d = 0;
		d++;
	}
}