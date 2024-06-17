/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:09:14 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/17 07:46:12 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_wordhan	*get_word_handler(void)
{
	t_wordhan	*handler;

	handler = (t_wordhan *)safe_malloc(sizeof(t_wordhan));
	handler->word = NULL;
	handler->field = 'c';
	handler->redir = 0;
	handler->is_redir_mode = 0;
	handler->concat = 0;
	return (handler);
}
