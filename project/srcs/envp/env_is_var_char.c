#include "../../incs/minishell.h"

bool env_is_var_char(char c)
{
    return (ft_isalnum(c) || c == '_');
}