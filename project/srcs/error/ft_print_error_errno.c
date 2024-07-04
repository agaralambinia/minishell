#include "../../incs/minishell.h"

void ft_print_error_errno(const char *shell, const char *cmd, const char *arg)
{
    ft_print_error(shell, cmd, arg, strerror(errno));
}
