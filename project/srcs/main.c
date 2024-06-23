/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/23 17:35:59 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
void	print_lexer_debug()
{
	t_list	*iter; //TODO убрать - для дебага
	t_token *t; //TODO убрать - для дебага

	iter = (t_list *)safe_malloc(sizeof(t_list *));
	iter = g_envp->token_list;
	t = (t_token *)safe_malloc(sizeof(t_token *));
	while (iter != NULL)
	{
		t = iter->content;
		printf(PINK"%i TYPE [%s]\n"RESET, t->token_type, t->token_content);
		iter = iter -> next;
	}
}

void	print_cmd_debug(t_list	*commands)
{
	t_list	*args;
	t_list	*in_redir;
	t_list	*out_redir;
	t_redir *redir;

	while (commands)
	{
		t_cmd *com = (t_cmd *)(commands->content);
		printf("COMMAND - %s\nARGS - ", com->command);
		args = com->args;
		while (args)
		{
			//printf("%s ", args->content); //TODO сереж тут компилятор ругается
			args = args->next;
		}
		printf("\nINPUT REDIRECTIONS:\n");
		in_redir = com->redir_in;
		while (in_redir)
		{
			redir = (t_redir  *)(in_redir->content);
			printf("PATH OR END - %s, IS_HEREDOC - %d\n", redir->path, redir->mode);
			in_redir = in_redir->next;
		}
		printf("OUTPUT REDIRECTIONS:\n");
		out_redir = com->redir_out;
		while (out_redir)
		{
			redir = (t_redir  *)(out_redir->content);
			printf("PATH - %s, IS_ADD_MODE - %d\n", redir->path, redir->mode);
			out_redir = out_redir->next;
		}
		commands = commands->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
  
	ft_singals();
	(void)argc; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argv; //TODO - чтобы компилилось с флагами, убрать позже
	
	t_list	*commands;

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
		

		line = readline(prompt_msg());
	}
	ft_lstclear(&commands, &free_cmd);
	system("leaks minishell");
	return (0);
}
