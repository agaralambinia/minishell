#include "../../incs/minishell.h"

int ft_split_count(char **split)
{
    int count = 0;
    while (split && split[count])
        count++;
    return count;
}
