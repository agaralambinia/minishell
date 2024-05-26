#include "../incs/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	//(void)envp; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argc; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argv; //TODO - чтобы компилилось с флагами, убрать позже
	envp_init(envp);
	// prompt_msg - кусок цикла уже, типо while (1)
	prompt_msg();
	return (0);
}