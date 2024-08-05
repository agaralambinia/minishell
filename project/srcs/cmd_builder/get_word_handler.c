/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:09:14 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/03 20:10:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_wordhan	*get_word_handler(void)
{
	t_wordhan	*handler;

	handler = (t_wordhan *)malloc(sizeof(t_wordhan));
	if (!handler)
		return (NULL);
	handler->word = NULL;
	handler->field = 'c';
	handler->redir = 0;
	handler->is_redir_mode = 0;
	handler->is_word_added = false;
	return (handler);
}
