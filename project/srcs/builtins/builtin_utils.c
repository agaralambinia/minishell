#include "../../incs/minishell.h"

void print_error(const char *shell, const char *cmd, const char *arg, const char *msg)
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

void print_error_errno(const char *shell, const char *cmd, const char *arg)
{
    print_error(shell, cmd, arg, strerror(errno));
}

int split_count(char **split)
{
    int count = 0;
    while (split && split[count])
        count++;
    return count;
}

void split_sort(char **split)
{
    int i, j;
    char *temp;
    int count = split_count(split);

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (ft_strcmp(split[j], split[j + 1]) > 0)
            {
                temp = split[j];
                split[j] = split[j + 1];
                split[j + 1] = temp;
            }
        }
    }
}
