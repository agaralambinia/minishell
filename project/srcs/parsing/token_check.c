/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:21:55 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 22:21:56 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	printlexerror(void)
{
	char	*err;

	err = "minishell: syntax error near unexpected token `newline'\n";
	printf("%s", err);
	return (0);
}

static int	check_redirs(t_list *t)
{
	if (t->next == NULL)
		return (printlexerror());
	t = t->next;
	if (((t_tn *)(t->dt))->t_tp == SP)
	{
		if (t->next != NULL)
			t = t->next;
		else
			return (printlexerror());
	}
	if (((t_tn *)(t->dt))->t_tp != WORD)
		return (printlexerror());
	return (1);
}

int	token_check(t_list *tlist)
{
	t_list	*t;

	t = tlist;
	if (!t)
		return (0);
	if (ft_lstsize(t) == 1 && ((t_tn *)(t->dt))->t_tp == SP)
		return (INT_MAX);
	while (t != NULL)
	{
		if ((((t_tn *)(t->dt))->t_tp == D_RA || ((t_tn *)(t->dt))->t_tp
			== D_LA || ((t_tn *)(t->dt))->t_tp == S_LA)
			|| ((t_tn *)(t->dt))->t_tp == S_RA)
		{
			if (!check_redirs(t))
				return (0);
		}
		t = t->next;
	}
	return (1);
}
