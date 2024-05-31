/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:46 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/31 20:50:05 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

typedef struct s_command
{
	char	*input;
	char	*command;
	char	*args;
	char	*output;
}			t_command;

/*
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
*/

void	get_pipeline()
{
	t_list	*token_lst;

	token_lst = g_envp->token_list;
	//word_len = 0;
	//token = (t_token *)malloc(sizeof(t_token));
	while (token_lst)
	{
		t_token *token = (t_token *)(token_lst->content);
		
		if (((int)(token->token_type)) == SPACE)
			printf("SPACE\n");
		/*
		if (token->content->token_type == WORD)
			printf("WORD\n");
		if (token->content->token_type == HARDWORD)
			printf("HARDWORD\n");
		if (token->content->token_type == SOFTWORD)
			printf("SOFTWORD\n");
		if (token->content->token_type == SINGLE_RA)
			printf("SINGLE_RA\n");
		if (token->content->token_type == DOUBLE_RA)
			printf("DOUBLE_RA\n");
		if (token->content->token_type == SINGLE_LA)
			printf("SINGLE_LA\n");
		if (token->content->token_type == PIPE)
			printf("PIPE\n");
		if (token->content->token_type == ENVP)
			printf("ENVP\n");
		if (token->content->token_type == ENVP)
			printf("ENVP\n");
			*/
		token_lst = token_lst->next;
	}
}
