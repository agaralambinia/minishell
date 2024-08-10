/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:40:13 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/10 13:12:00 by sosokin          ###   ########.fr       */
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
