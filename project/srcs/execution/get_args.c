/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:44:28 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/22 21:15:14 by sosokin          ###   ########.fr       */
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
	args[0] = cmd->command;
	tmp = cmd->args;
	i = 1;
	while (i < len)
	{
		args[i] = (char *)(tmp->content);
		i++;
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}
