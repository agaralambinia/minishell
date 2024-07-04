#include "../../incs/minishell.h"

bool	ft_is_numeric(char *str)
{
	int	index;

	index = 0;
	if (str[0] == '\0')
	{
		ft_print_error(SHELL_NAME, "exit", str, "numeric argument required");
		return (false);
	}
	else if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
		{
			ft_print_error(SHELL_NAME, "exit", str, "numeric argument required");
			return (false);
		}
		index++;
	}
	return (true);
}
