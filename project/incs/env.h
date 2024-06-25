#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>

# define ERROR		-1
# define SHELL_NAME	"minishell"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_envp
{
    t_list *envp_list;
    t_list *token_list;
} t_envp;
extern t_envp	*g_envp;

int     env_init(void);
char    *env_get_value(char *name);
char    *env_find_var(char *name);
bool    env_var_is_value(char *var_name, char *value);
bool    env_is_var_char(char c);
int     env_unset_var(char *name);
int     env_put_var(char *str);
int     env_set_env(char *name, char *value);

#endif
