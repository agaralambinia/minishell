/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:44:28 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/04 18:30:23 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	**get_args(t_cmd *cmd)
{
	t_list	*tmp;
	int		len;
	char	**args;
	int		i;

	len = ft_lstsize(cmd->args);
	len++;
	args = (char **)malloc(sizeof(char *) * (len + 1));
	args[0] = ft_strdup(cmd->command);
	tmp = cmd->args;
	i = 1;
	while (i < len)
	{
		args[i] = ft_strdup((char *)(tmp->dt));
		i++;
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}
