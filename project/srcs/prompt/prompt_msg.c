/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:40:31 by defimova          #+#    #+#             */
/*   Updated: 2024/07/10 19:31:29 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*parse_dir(char *dir, t_envp *envp_var)
{
	char	*home;

	if (!dir)
		return (NULL);
	home = get_envp_list_val("HOME", &(envp_var->envp_list));
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

	dir = getcwd(buf, 4096);
	parsed_dir = parse_dir(dir, envp_var);
	if (!parsed_dir)
		return (NULL);
	result = ft_strjoin("minishell:", parsed_dir);
	free(parsed_dir);
	parsed_dir = ft_strjoin(result, " minishell_user$ ");
	free(result);
	return (parsed_dir);
}
