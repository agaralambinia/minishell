#include "../incs/minishell.h"

char	*parse_dir(char *dir)
{
	char	*home;
	if (!dir)
		return (NULL);
	home = get_var_value("HOME");
	if (ft_strncmp(dir, home, ft_maxint(ft_strlen(dir), ft_strlen(home))) == 0)
		return(ft_strdup("~"));
	else 
		return (ft_strdup(ft_strrchr(dir, '/') + 1));
}

void	prompt_msg(void)
{
	char	*dir;
	char	buf[4097];
	char	*parsed_dir;

	dir = getcwd(buf, 4096);
	parsed_dir = parse_dir(dir);
	printf(GREEN"minishell:%s minishell_user$\n"RESET, parsed_dir);
	free(parsed_dir);
}