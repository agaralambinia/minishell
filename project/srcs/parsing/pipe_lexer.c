/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:15:15 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 22:15:18 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	pipe_checker(t_envp *envp_var, char *line)
{
	t_list	*l;
	t_list	*pl;

	l = (ft_lstlast(envp_var->token_list));
	pl = (ft_lstprelast(envp_var->token_list));
	if (!l && *(line + 1) == '|')
	{
		printf("minishell: syntax error near unexpected token `||'\n");
		return (0);
	}
	if (!l
		|| ((t_tn *)(l->dt))->t_tp == PIPE
		|| (((t_tn *)(l->dt))->t_tp == SP
		&& (ft_lstsize(envp_var->token_list) == 1))
		|| (((t_tn *)(l->dt))->t_tp == SP
		&& ((t_tn *)(pl->dt))->t_tp == PIPE)
	)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	pipe_lexer(char *line, int *i, t_envp *envp_var)
{
	t_tn	*t;

	t = (t_tn *)safe_malloc(sizeof(t_tn));
	ft_straddchar(&t->data, line[(*i)++]);
	if (!pipe_checker(envp_var, line))
	{
		free_token(t);
		return (0);
	}
	t->t_tp = PIPE;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(t));
	return (1);
}
