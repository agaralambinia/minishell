#include <readline/readline.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *line = readline("Enter a line");
	printf("%s\n", line);
}