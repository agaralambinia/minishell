/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:59:25 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/11 17:08:30 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_envp(t_list *envp_list)
{
	while(envp_list)
	{
		printf("%s\n", (char *)envp_list->dt);
		envp_list = envp_list->next;
	}

}

void	print_lexer_debug(t_envp *envp_var)
{
	t_list	*iter; //TODO убрать - для дебага
	t_tn *t; //TODO убрать - для дебага

	iter = (t_list *)safe_malloc(sizeof(t_list));
	iter = envp_var->token_list;
	t = (t_tn *)safe_malloc(sizeof(t_tn));
	while (iter != NULL)
	{
		t = iter->dt;
		printf(PINK"%i TYPE [%s]\n"RESET, t->t_tp, t->data);
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
		t_cmd *com = (t_cmd *)(commands->dt);
		printf("COMMAND - %s\nARGS - ", com->command);
		args = com->args;
		while (args)
		{
			//printf("%s ", args->dt); //TODO сереж тут компилятор ругается
			args = args->next;
		}
		printf("\nINPUT REDIRECTIONS:\n");
		in_redir = com->redir_in;
		while (in_redir)
		{
			redir = (t_redir  *)(in_redir->dt);
			printf("PATH OR END - %s, IS_HEREDOC - %d\n", redir->path, redir->mode);
			in_redir = in_redir->next;
		}
		printf("OUTPUT REDIRECTIONS:\n");
		out_redir = com->redir_out;
		while (out_redir)
		{
			redir = (t_redir  *)(out_redir->dt);
			printf("PATH - %s, IS_ADD_MODE - %d\n", redir->path, redir->mode);
			out_redir = out_redir->next;
		}
		commands = commands->next;
	}
}
