/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:19:31 by defimova          #+#    #+#             */
/*   Updated: 2024/07/12 16:01:38 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define READLINE_LIBRARY
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
#include <limits.h>
# include "../libs/rl_lib/include/readline/readline.h"
# include "../libs/rl_lib/include/readline/history.h"
//# include <readline/readline.h>
//# include <readline/history.h>

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
	SP = 32,
	WORD = 2,
	HARDWORD = 3,
	SOFTWORD = 4,
	SINGLE_RA = 5,
	DOUBLE_RA = 6,
	SINGLE_LA = 7,
	DOUBLE_LA = 8,
	PIPE = 9,
	ENVP = 10,
	EXITSTATUS = 11
}	t_token_type;

typedef enum	s_quote
{
	SINGLE,
	DOUBLE,
	NA,
}	t_quote;

typedef enum	s_exec_status
{
	SUCCESS,
	ERROR,
	NOTFOUND
}	t_exec_status;

/*
сруктура для хранения токена	
	token_type: тип токена - одно из значений t_token_type;
	t_data: строка-значение токена;
*/
typedef struct s_token
{
	int		token_type;
	char	*t_data;
}	t_token;

//структура для обработки очередного токена типа WORD, SOFTWORD, HARDWORD
//	word:		накопленное значение для записи в поле
//	field:		обозначение поля для записи в структуру t_cmd (команда либо аргументы)
//	redir:		обозначение поля для записи в структуру t_cmd (перенаправлениe ввода-вывода)
//	redir_mode:	флаг обозначения специального режима перенаправления ввода-вывода
//	concat:		обозначение поля в которое нужно дописать  текущее словo	
typedef struct s_wordhan
{
	char	*word;
	char	field;
	char	redir;
	int		is_redir_mode;
}			t_wordhan;

//структура для хранения данных о перенаправлении ввода-вывода
//	path: путь до файла для перенаправления
//	mode: режим перенаправления (получение данных из обычного
//	файла или файла heredoc для in; перезапись файла или дозапись в файл для out)
typedef struct s_redir
{
	char	*path;
	int		mode;
}			t_redir;

//структура для хранения отдельной команды
//	command: 	имя команды
//	args:		аргументы команды
//	redirs_in:	список перенаправлений входа
//	redirs_out:	список перенаправлений вывода
typedef struct s_cmd
{
	char	*command;
	t_list	*args;
	t_list	*redir_in;
	t_list	*redir_out;
}			t_cmd; 

/*
сруктура глобальной переменной	
	envp_list: связанный список переменных окружения;
	token_list: связанный список токенов (t_token) последнего промпта;
*/
typedef struct s_envp
{
	t_list	*envp_list;
	t_list	*token_list;
	int		last_code;
}	t_envp;

typedef struct s_builtins
{
    const char  *name;
    int         (*func)(int argc, char **argv);
}	t_builtins;

# define SHELL_NAME	"minishell"

#ifndef PATH_MAX
#	define PATH_MAX	1024
#endif

// цвета для printf. Не забывай RESET
# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define PINK	"\033[1;35m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"

// prompt funcs
char	*prompt_msg(t_envp *envp_var);

// error funcs
void	ft_exit_error(char *error);
void	ft_print_error(const char *shell, const char *cmd, const char *arg, const char *msg);
void	ft_print_error_errno(const char *shell, const char *cmd, const char *arg);

// envp funcs
void	envp_init(char **envp, t_envp **envp_var);
char	*get_envp_list_val(char *var, t_list **envp_list);
int     env_init(void);
bool    env_var_is_value(char *var_name, char *value);
int     env_unset_var(char *name, t_envp *envp_var);
int		env_put_var(char *name, char *str, t_envp *envp_var);
int		env_set_env(char *name, char *value, t_envp *envp_var);

// parsing funcs
int		lexer(char *line, t_envp *envp_var);
void	word_lexer(char *line, int *i, t_envp *envp_var);
void	quote_lexer(char *l, int *i, t_quote qtype, t_envp *envp_var);

// signal funcs
void	ft_singals(void);

// utils
bool	ft_strbegins(char *s1, char *s2);
void	ft_straddchar(char **str, char c);
int		ft_maxint(int i1, int i2);
bool	ft_isspace(const char a);
bool	ft_isspecial(const char a);
char	*get_env_val(char *envvar, t_envp *envp_var);
int		ft_arrlen(void **arr);
void	check_for_exit(char *msg, int pred);
void	free_arr(void **arr);
void	free_cmd(void *data);
void	free_token(void *data);
void	free_mock(void *data);
bool	ft_is_numeric(char *str);
void	ft_list_sort(t_list *lst);
int		ft_list_replace(t_envp *envp_var, char *old_var, char *new_var);
int		ft_list_remove(char *env_var, t_list **envp_list);
int		ft_split_count(char **split);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

// wraps
void	*safe_malloc(size_t str);

// cmd_builder
t_list		*get_commands(t_envp *envp_var);
t_wordhan	*get_word_handler(void);
t_cmd		*get_new_command(void);
int			add_to_word(char *word, t_wordhan *handler);
int			bind_field(t_cmd *com, t_wordhan *handler);
void		free_res(t_list **com_lst, t_cmd **com);

//execution
char	**get_args(t_cmd *cmd);
int		**get_pipes(int cmd_cnt);
void	redir_in(t_cmd *cmd);
void	redir_out(t_cmd *cmd);
void	run(char **paths, char **args, t_envp *envp_var);
int		run_command(t_list *cmd_lst, t_envp *envp_var);
void	setup_pipes_first(int **pp);
void	setup_pipes_last(int **pp, int count);
void	setup_pipes_parent(int **pp);

// buildins
int		builtin_exec(char **argv, bool subshell, t_envp *envp_var);
int		builtin_cd(int argc, char **argv, t_envp *envp_var);
int		builtin_echo(char **argv);
int		builtin_env(t_envp *envp_var);
int		builtin_export(int argc, char **argv, t_envp *envp_var);
int		builtin_pwd(t_envp *envp_var);
int		builtin_unset(char **argv, t_envp *envp_var);

// debug
void	print_envp(t_list *envp_list);
void	print_lexer_debug(t_envp *envp_var);
void	print_cmd_debug(t_list	*commands);

#endif
