/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:34:24 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/13 21:34:34 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_redir(void *data)
{
	t_redir	*redir;	

	redir = (t_redir *)data;
	if (redir)
	{
		free(redir->path);
		free(redir);
	}
}
