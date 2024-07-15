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
	while (envp_list)
	{
		printf("%s\n", (char *)envp_list->dt);
		envp_list = envp_list->next;
	}
}

void	print_lexer_debug(t_envp *envp_var)
{
	t_list	*iter;
	t_tn	*t;

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
	t_list	*in_r;
	t_list	*out_r;

	while (commands)
	{
		printf("COMMAND - %s\nARGS - ", ((t_cmd *)(commands->dt))->command);
		args = ((t_cmd *)(commands->dt))->args;
		while (args)
			args = args->next;
		in_r = ((t_cmd *)(commands->dt))->redir_in;
		while (in_r)
		{
			printf("%s%d", ((t_r *)(in_r->dt))->path, ((t_r *)(in_r->dt))->m);
			in_r = in_r->next;
		}
		printf("OUTPUT REDIRECTIONS:\n");
		out_r = ((t_cmd *)(commands->dt))->redir_out;
		while (out_r)
		{
			printf("%s,%d", ((t_r *)(in_r->dt))->path, ((t_r *)(in_r->dt))->m);
			out_r = out_r->next;
		}
		commands = commands->next;
	}
}


