/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:40:13 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/04 19:49:12 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_envp(t_list *envp_list)
{
	while (envp_list)
	{
		printf("%s\n", (char *)envp_list->dt);
		envp_list = envp_list->next;
	}
}

void	print_lexer_debug(t_list *token_list)
{
	t_list	*iter;
	t_tn	*t;

	iter = token_list;
	while (iter != NULL)
	{
		t = iter->dt;
		printf(PINK "%i TYPE [%s]\n" RESET, t->t_tp, t->data);
		iter = iter->next;
	}
}

static void	print_cmd_args(t_cmd *com)
{
	t_list	*args;

	printf("ARGS - ");
	args = com->args;
	while (args)
	{
		printf("%s ", args->dt);
		args = args->next;
	}
}

static void	print_in_redir(t_cmd *com)
{
	t_list	*in_redir;
	t_r		*redir;

	printf("\nINPUT REDIRECTIONS:\n");
	in_redir = com->redir_in;
	while (in_redir)
	{
		redir = (t_r *)(in_redir->dt);
		printf("PATH OR END - %s, IS_HEREDOC - %d\n", redir->path, redir->m);
		in_redir = in_redir->next;
	}
}

static void	print_out_redir(t_cmd *com)
{
	t_list	*out_redir;
	t_r		*redir;

	printf("OUTPUT REDIRECTIONS:\n");
	out_redir = com->redir_out;
	while (out_redir)
	{
		redir = (t_r *)(out_redir->dt);
		printf("PATH - %s, IS_ADD_MODE - %d\n", redir->path, redir->m);
		out_redir = out_redir->next;
	}
}

void	print_cmd_list(t_list *commands)
{
	t_cmd	*com;

	while (commands)
	{
		com = (t_cmd *)(commands->dt);
		printf("COMMAND - %s\n", com->command);
		print_cmd_args(com);
		print_in_redir(com);
		print_out_redir(com);
		commands = commands->next;
	}
}

void	print_cmd(t_cmd *com)
{
	if (!com)
	{
		printf("COM IS NULL %p", com);
		return ;
	}
	printf("COMMAND - %s\n", com->command);
	print_cmd_args(com);
	print_in_redir(com);
	print_out_redir(com);
}