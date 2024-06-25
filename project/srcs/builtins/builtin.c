#include "builtin.h"

static const struct	s_builtins g_builtins[] = {
	{"cd", builtin_cd},
	{"echo", builtin_echo},
	{"env", builtin_env},
	{"export", builtin_export},
	{"pwd", builtin_pwd},
	{"unset", builtin_unset}
	{NULL, NULL},
};

int	builtin_check(char **argv)
{
	int	name_length;
	int	index;

	index = 0;
	if (argv[0] && !ft_strncmp(argv[0], "exit", 5))
		return (INT_MAX);
	while (g_builtins[index].name != NULL && argv)
	{
		name_length = ft_strlen(g_builtins[index].name);
		if (argv[0] && !ft_strncmp(argv[0], g_builtins[index].name, name_length + 1))
			return (index + 1);
		index++;
	}
	return (0);
}

int	builtin_exec(char **argv, bool subshell, t_list *free_list)
{
	int	builtin_index;

	builtin_index = builtin_check(argv);
	if (builtin_index == 0)
		return (ERROR);
	errno = 0;
	if (builtin_index == INT_MAX)
		return (builtin_exit(split_count(argv), argv, subshell, free_list));
	return (g_builtins[builtin_index - 1].func(split_count(argv), argv));
}
