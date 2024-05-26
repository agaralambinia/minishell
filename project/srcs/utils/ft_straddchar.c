#include "../../incs/minishell.h"

char	*ft_straddchar(char *str, char c)
{
	size_t	i;
	size_t	strlen;
	char	*result;

	if (!str || !c)
		return (NULL);
	strlen = ft_strlen(str);
	result = (char *) safe_malloc((strlen + 2) * sizeof(char));
	i = -1;
	while (++i < strlen)
		*(result + i) = *(str + i);
	*(result + i) = c;
	return (result);
}