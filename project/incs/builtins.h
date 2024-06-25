#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include "env.h"
# include "libft.h"

struct s_builtins
{
    const char  *name;
    int         (*func)(int argc, char **argv);
};

int builtin_check(char **argv);
int builtin_exec(char **argv, bool subshell, t_list *l_free);
int builtin_cd(int argc, char **argv);
int builtin_echo(int argc, char **argv);
int builtin_env(int argc, char **argv);
int builtin_exit(int argc, char **argv, bool subshell, t_list *l_free);
int builtin_export(int argc, char **argv);
int builtin_pwd(int argc, char **argv);
int builtin_unset(int argc, char **argv);
void print_error(const char *shell, const char *cmd, const char *arg, const char *msg);
void print_error_errno(const char *shell, const char *cmd, const char *arg);
int split_count(char **split);
void split_sort(char **split);

#endif
