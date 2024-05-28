#include "../../incs/minishell.h"

bool	ft_isspace(const char a)
{
	if ((a == ' ') || (a == '\n') || (a == '\t') || (a == '\v')
		|| (a == '\f') || (a == '\r'))
	{
		return (true);
	}
	else
		return (false);
}