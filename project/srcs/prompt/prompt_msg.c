/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:40:31 by defimova          #+#    #+#             */
/*   Updated: 2024/06/06 20:58:53 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*parse_dir(char *dir, t_envp *envp_var)
{
	char	*home;

	printf(PINK"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	if (!dir)
		return (NULL);
	printf(PINK"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	home = get_envp_list_val("HOME", &(envp_var->envp_list));
	printf(PINK"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	if (ft_strncmp(dir, home, ft_maxint(ft_strlen(dir), ft_strlen(home))) == 0)
		return (ft_strdup("~"));
	else if (ft_strncmp(dir, "/", ft_strlen(dir)) == 0)
		return (ft_strdup("/"));
	else
		return (ft_strdup(ft_strrchr(dir, '/') + 1));
}

char	*prompt_msg(t_envp *envp_var)
{
	char	*dir;
	char	buf[4097];
	char	*parsed_dir;
	char	*result;

	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	dir = getcwd(buf, 4096);
	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	parsed_dir = parse_dir(dir, envp_var);
	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	result = ft_strjoin("minishell:", parsed_dir);
	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	parsed_dir = ft_strjoin(result, " minishell_user$ ");
	printf(BLUE"DEBUG %s %d\n"RESET, __FILE__, __LINE__);
	free(result);
	return (parsed_dir);
}
