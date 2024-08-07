/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:05:45 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/09 20:11:21 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	free_token(void *data)
{
	t_tn	*token;	

	token = (t_tn *)data;
	if (token)
	{
		free(token->data);
		free(token);
	}
}
