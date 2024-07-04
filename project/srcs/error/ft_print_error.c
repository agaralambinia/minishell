#include "../../incs/minishell.h"

void ft_print_error(const char *shell, const char *cmd, const char *arg, const char *msg)
{
    ft_putstr_fd(shell, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    if (cmd)
    {
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
    }
    if (arg)
    {
        ft_putstr_fd(arg, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
    }
    if (msg)
        ft_putstr_fd(msg, STDERR_FILENO);
    ft_putchar_fd('\n', STDERR_FILENO);
}
