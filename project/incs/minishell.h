#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <readline/readline.h>

/*
enum кодов наименования типа токена
	- SPACE 		пробельные символы
	- WORD 			любой набор символов без разделителя
	- HARDWORD 		любой набор символов, заключенный в ''
	- SOFTWORD 		любой набор символов, заключенный в ""
	- SINGLE_RA 	>
	- DOUBLE_RA 	>>
	- SINGLE_LA 	<
	- DOUBLE_LA 	<<
	- PIPE			|
	- ENVP			переменная окружения ($ и слово после него)
*/
typedef enum	s_token_type
{
	SPACE,
	WORD,
	HARDWORD,
	SOFTWORD,
	SINGLE_RA,
	DOUBLE_RA,
	SINGLE_LA,
	DOUBLE_LA,
	PIPE,
	ENVP,
}	t_token_type;

/*
сруктура для хранения токена	
	token_type: тип токена - одно из значений t_token_type;
	token_content: строка-значение токена;
*/
typedef struct s_token
{
	int		token_type;
	char	*token_content;
}	t_token;

/*
сруктура глобальной переменной	
	envp_list: связанный список переменных окружения;
	token_list: связанный список токенов (t_token) последнего промпта;
*/
typedef struct s_envp
{
	t_list	*envp_list;
	t_list	*token_list;
}	t_envp;

// глобальная переменная
t_envp	*g_envp;

// цвета для printf. Не забывай RESET
# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define PINK	"\033[1;35m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"

// prompt funcs
char	*prompt_msg(void);

// error funcs
void	ft_exit_error(char *error);

// envp funcs
void	g_envp_init(char **envp);
char	*get_envp_list_val(char *var);

// parsing funcs
void	lexer(char *line);

// utils
bool	ft_strbegins(char *s1, char *s2);
char	*ft_straddchar(char *str, char c);
int		ft_maxint(int i1, int i2);
bool	ft_isspace(const char a);
bool	ft_isspecial(const char a);

// wraps
void	*safe_malloc(size_t str);

#endif