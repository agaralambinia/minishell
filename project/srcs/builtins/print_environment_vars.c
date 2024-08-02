/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environment_vars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:58:55 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/02 20:03:01 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	print_with_value(int fd, char *temp, t_list *e_cp)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('"', fd);
	ft_putstr_fd((ft_strchr(e_cp->dt, '=') + 1), fd);
	ft_putendl_fd("\"", fd);
}

static void	print_without_value(int fd, char *temp)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putendl_fd(temp, fd);
}

void	print_environment_vars(t_envp *envp_var, int fd)
{
	t_list	*e_cp;
	char	*temp;
	int		i;

	if (envp_var == NULL)
		return ;
	e_cp = envp_var->envp_list;
	ft_list_sort(e_cp);
	while (e_cp != NULL)
	{
		i = 0;
		while (((char *)e_cp->dt)[i] != '=')
			i++;
		temp = (char *)safe_malloc(sizeof(char) * (i + 1));
		temp = ft_strncpy(temp, e_cp->dt, i + 1);
		if (ft_strchr(e_cp->dt, '='))
			print_with_value(fd, temp, e_cp);
		else
			print_without_value(fd, temp);
		e_cp = e_cp->next;
		free(temp);
	}
}
