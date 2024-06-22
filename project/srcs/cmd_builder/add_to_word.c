/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:33:07 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/17 07:54:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_to_word(char *word, t_wordhan *handler)
{
	char	*tmp;
	int		is_freeable;

	is_freeable = 1;
	if (!(handler->word))
	{
		handler->word = "";
		is_freeable = 0;
	}
	tmp = handler->word; 
	handler->word = ft_strjoin(handler->word, word);
	if (is_freeable)
		free(tmp);
}
