#include "../../incs/minishell.h"

static void	ft_controlc(int signal)
{
	if (signal == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0); //TODO не компилится
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_singals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_controlc);
}
