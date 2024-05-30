#include "../../incs/minishell.h"

bool	ft_isspecial(const char a)
{
	if ((a == '\'') || (a == '\"') || (a == '$') || (a == '|')
		|| (a == '>') || (a == '<'))
	{
		return (true);
	}
	else
		return (false);
}