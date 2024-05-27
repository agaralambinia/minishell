#ifndef MINISHELL_H
# define MINISHELL_H

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
char	*parse_dir(char *dir);

// error funcs
void	ft_exit_error(char *error);

// string funcs
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
bool	ft_strbegins(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_straddchar(char *str, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// int funcs
int		ft_maxint(int i1, int i2);

// env funcs
void	envp_init(char **envp);
char	*get_var_value(char *var);

// function wraps
void	*safe_malloc(size_t str);

// memory funcs
void	ft_bzero(void *s, size_t n);

#endif