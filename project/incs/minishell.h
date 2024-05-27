#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// глобальная переменная для хранения переменных окружения
char	**g_envp;

// цвета для printf. Не забывай RESET
# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define PINK	"\033[1;35m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"

// prompt funcs
void	prompt_msg(void);

// error funcs
void	ft_exit_error(char *error);

// envp funcs
void	envp_init(char **envp);
char	*get_var_value(char *var);

// utils
bool	ft_strbegins(char *s1, char *s2);
char	*ft_straddchar(char *str, char c);
int		ft_maxint(int i1, int i2);

// wraps
void	*safe_malloc(size_t str);

#endif