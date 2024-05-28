/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/28 11:44:05 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

typedef struct s_token
{
	char	*input;
	char	*command;
	char	*args;
	char	*output;
}			t_token;

static int	isdivider(char c)
{
	//TODO прояснить насчет перевода строки, по идее он не разделяет слова, а 
	//заканчивает строку
	if (c == ' ' || (c > 10 && c < 14))
		return (1);
	return (0);
}

static void	bind(t_token *token, char *word, char field)
{
	if (field == 'i')
		token->input = word;
	if (field == 'c')
		token->command = word;
	if (field == 'a')
		token->args = word;
	if (field == 'o')
		token->output = word; 
}

void	get_tokens(char *str)
{
	t_list	*tokens;
	t_token	*token;
	size_t	word_len;
	char	fieldptr;
	char	*word;

	word_len = 0;
	token = (t_token *)malloc(sizeof(t_token));
	while (*str)
	{
		if (isdivider(*str) && word_len > 0)
		{
			word = (char *)malloc(sizeof(char) * (word_len + 1));	
			ft_strlcpy(word, str - word_len, word_len + 1);
			bind(token, word, fieldptr);
			word_len = 0;
		}
		if (*str == '<' && word_len == 0)
			fieldptr = 'i';	
		else if (*str == '>' && word_len == 0)
			fieldptr = 'o';	
		else
		{
			if (word_len == 0)
			{
				if (fieldptr == 'c')
					fieldptr == 'a';
				else
					fieldptr == 'c';
			}
			word_len++;
		}
		str++;
	}
}
