/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/07 16:33:22 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
  
//	t_list	*iter; //TODO убрать - для дебага
//	t_token *t; //TODO убрать - для дебага

	(void)argc; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argv; //TODO - чтобы компилилось с флагами, убрать позже
	
	t_list	*commands;
	t_list	*args;

	g_envp_init(envp);
	line = readline(prompt_msg());
	while (line)
	{
		add_history(line);
		lexer(line);
		printf("Lexer done\n");

		commands = get_commands();
		printf("Command parsing done\n");

		run_command(commands);
		while (commands)
		{
			t_cmd *com = (t_cmd *)(commands->content);
			printf("INPUT - %s\nCOMMAND - %s\nARGS - ", com->input, com->command);
			args = com->args;
			while (args)
			{
				printf("%s ", args->content); //TODO сереж тут компилятор ругается
				args = args->next;
			}
			printf("\nOUTPUT - %s\nINMODE - %d\nOUTMODE - %d\n", com->output, com->inmode, com->outmode);
			commands = commands->next;
		}
		
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
