#include "../../incs/minishell.h"

int env_put_var(char *str, t_envp *envp_var)
{
    char *old_var;
    char *new_var;

    if (str == NULL || ft_strchr(str, '=') == NULL)
        return (ERROR);

    new_var = ft_strdup(str);
    if (new_var == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    old_var = get_env_val(str - 1, envp_var);
	printf("%s %d\n", __FILE__, __LINE__);
    ft_list_replace(envp_var, old_var, new_var);
	printf("%s %d\n", __FILE__, __LINE__);
    free(new_var);
	printf("%s %d\n", __FILE__, __LINE__);
    return (SUCCESS);
}
