#include "../../incs/minishell.h"

int env_set_env(char *name, char *value, t_envp *envp_var)
{
    char *var_str;
    char *tmp;
    int status;

    if (name == NULL || value == NULL)
        return (ERROR);

    tmp = ft_strjoin(name, "=");
	printf("%s\n", tmp);
    if (tmp == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
    var_str = ft_strjoin(tmp, value);
	printf("%s\n", var_str);
    free(tmp);
    if (var_str == NULL)
    {
        ft_print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
        return (ERROR);
    }
	printf("%s %d\n", __FILE__, __LINE__);
    status = env_put_var(var_str, envp_var);
    free(var_str);
	printf("%s %d\n", __FILE__, __LINE__);
    return (status);
}
