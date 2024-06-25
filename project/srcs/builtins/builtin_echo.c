#include "builtin.h"

int	builtin_echo(int argc __attribute((unused)), char **argv)
{
	int		index;
	bool	include_newline;

	include_newline = false;
	index = 1;
	while (argv[index] && !ft_strncmp(argv[index], "-n", 3))
		index++;
	if (index == 1)
		include_newline = true;
	while (argv[index])
	{
		ft_putstr_fd(argv[index], 1);
		if (argv[index + 1])
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (include_newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
