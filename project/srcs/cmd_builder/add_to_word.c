/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:33:07 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/03 20:10:01 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	add_to_word(char *word, t_wordhan *handler)
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
	if (!(handler->word))
		return (0);
	handler->is_word_added = true;
	return (1);
}
