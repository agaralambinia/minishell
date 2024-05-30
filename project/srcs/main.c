/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/25 19:04:34 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	//t_list	*iter; //TODO убрать - для дебага
	//t_token *t; //TODO убрать - для дебага

	(void)argc; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argv; //TODO - чтобы компилилось с флагами, убрать позже
	g_envp_init(envp);
	line = readline(prompt_msg());
	while (line)
	{
		add_history(line);
		printf("You type %s, great...\n", line);
		lexer(line);
		//раскомментируй код ниже чтоб посмотреть на лексер
		/*
		iter = (t_list *)safe_malloc(sizeof(t_list *));
		iter = g_envp->token_list;
		t = (t_token *)safe_malloc(sizeof(t_token *));
		while (iter != NULL)
		{
			t = iter->content;
			printf(PINK"%i TYPE [%s]\n"RESET, t->token_type, t->token_content);
			iter = iter -> next;
		}
		*/
		line = readline(prompt_msg());
	}
	return (0);
}
