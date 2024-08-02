/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:19:31 by defimova          #+#    #+#             */
/*   Updated: 2024/08/02 20:24:04 by sosokin          ###   ########.fr       */
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
# include <limits.h>
# include "../libs/rl_lib/include/readline/readline.h"
# include "../libs/rl_lib/include/readline/history.h"

typedef enum s_t_tp
{
	SP = 32,
	WORD = 2,
	HARDWORD = 3,
	SOFTWORD = 4,
	S_RA = 5,
	D_RA = 6,
	S_LA = 7,
	D_LA = 8,
	PIPE = 9,
	ENVP = 10,
	EXITSTATUS = 11
}	t_t_tp;

typedef enum s_quote
{
	SINGLE,
	DOUBLE,
	NA,
}	t_quote;

typedef enum s_exec_status
{
	SUCCESS,
	ERROR,
	NOCMD,
	NOTFOUND = INT_MAX
}	t_exec_status;

typedef struct s_tn
{
	int		t_tp;
	char	*data;
}	t_tn;

typedef struct s_wordhan
{
	char	*word;
	char	field;
	char	redir;
	int		is_redir_mode;
}			t_wordhan;

typedef struct s_r
{
	char	*path;
	int		m;
}			t_r;

typedef struct s_cmd
{
	char	*command;
	t_list	*args;
	t_list	*redir_in;
	t_list	*redir_out;
}			t_cmd;

typedef struct s_envp
{
	t_list	*envp_list;
	t_list	*token_list;
	int		last_code;
	bool	is_exit;
	bool	hide_prompt;
}	t_envp;

typedef struct s_builtins
{
	const char	*name;
	int			(*func)(int argc, char **argv);
}	t_builtins;

# define SHELL_NAME	"minishell"

# ifndef PATH_MAX
#  define PATH_MAX	1024
# endif

# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define PINK	"\033[1;35m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"

char			*prompt_msg(t_envp *envp_var);
void			ft_exit_error(char *error);
void			ft_print_error(const char *shell, const char *cmd,
					const char *arg, const char *msg);
void			ft_print_error_errno(const char *shell, const char *cmd,
					const char *arg);
void			envp_init(char **envp, t_envp **envp_var);
char			*get_envp_list_val(char *var, t_list **envp_list);
int				env_init(void);
bool			env_var_is_value(char *var_name, char *value);
int				env_unset_var(char *name, t_envp *envp_var);
int				env_put_var(char *name, char *str, t_envp *envp_var);
int				env_set_env(char *name, char *value, t_envp *envp_var);
int				lexer(char **line, t_list **token_list, t_envp *envp_var);
int				word_lexer(char *line, int *i, t_envp *envp_var,
					t_list **token_list);
void			quote_lexer(char *l, int *i, t_quote qtype, void **common_data);
int				pipe_lexer(char *line, int *i, t_list **token_list);
int				redirect_lexer(char *line, int *i, t_list **token_list);
int				token_check(t_list **tlist, t_envp *envp_var, char **hline);
void			ft_singals(void);
bool			ft_strbegins(char *s1, char *s2);
void			ft_straddchar(char **str, char c);
int				ft_maxint(int i1, int i2);
bool			ft_isspace(const char a);
bool			ft_isspecial(const char a);
char			*get_env_val(char *envvar, t_envp *envp_var);
int				ft_arrlen(void **arr);
void			check_for_exit(char *msg, int pred);
void			free_arr(void **arr);
void			free_cmd(void *data);
void			free_token(void *data);
void			free_mock(void *data);
void			free_redir(void *data);
void			free_envp(t_envp *envp_var);
bool			ft_is_numeric(char *str);
void			ft_list_sort(t_list *lst);
int				ft_list_replace(t_envp *envp_var, char *old_var, char *new_var);
int				ft_list_remove(char *env_var, t_list **envp_list);
int				ft_split_count(char **split);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
t_list			*ft_lstprelast(t_list *lst);
void			*safe_malloc(size_t str);
t_list			*get_commands(t_list *token_lst, t_envp *envp_var);
t_wordhan		*get_word_handler(void);
t_cmd			*get_new_command(void);
int				add_to_word(char *word, t_wordhan *handler);
int				bind_field(t_cmd *com, t_wordhan *handler);
void			free_res(t_list **com_lst, t_cmd **com, t_wordhan *handler);
int				handle_token(void **info_cont, t_cmd **com, t_list **com_lst,
					t_envp *envp_var);
t_cmd			*add_command(t_cmd *com, t_list **com_lst, t_wordhan *handler);
char			**get_args(t_cmd *cmd);
int				**get_pipes(int cmd_cnt);
void			redir_in(t_cmd *cmd);
void			redir_out(t_cmd *cmd);
void			run(char **args, t_envp *envp_var);
int				run_command(t_list *cmd_lst, t_envp *envp_var);
int				run_single(t_list *cmd, t_envp *envp_var);
int				get_exit(int exit_info, bool is_fork_ov);
void			setup_pipes_first(int **pp);
void			setup_pipes_last(int **pp, int count);
void			setup_pipes_parent(int **pp);
int				builtin_exec(char **argv, t_envp *envp_var, t_cmd *cmd);
int				builtin_cd(int argc, char **argv, t_envp *envp_var, t_cmd *cmd);
int				builtin_echo(char **argv, t_cmd *cmd);
int				builtin_env(t_envp *envp_var, t_cmd *cmd);
int				builtin_export(int argc, char **argv, t_envp *envp_var, t_cmd *cmd);
int				builtin_pwd(t_envp *envp_var, t_cmd *cmd);
int				builtin_unset(char **argv, t_envp *envp_var, t_cmd *cmd);
unsigned char	builtin_exit(char **argv, t_envp *envp_var, t_cmd *cmd);
int				check_for_error(char *msg, int pred);
int				handle_redirs(t_cmd *cmd);
int				handle_in_redir(t_cmd *cmd);
int				handle_out_redir(t_cmd *cmd);
void			setup_pipes_mid(int **pp, int ind, t_cmd *cmd);
void			run_mid(t_cmd *cmd, int **pp, int ind, t_envp *envp_var);
void			tn_clean_null(t_list **tlist);
long long		ft_atoll_p(const char *str, int *is_int);
bool			is_in_env_list(char *name, t_list **envp_list);
void			print_environment_vars(t_envp *envp_var, int fd);

#endif
