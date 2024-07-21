/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:16:27 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 22:16:29 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	doublela_checker(char *s, int *i, char *err)
{
	if (s[*i + 1] != '<')
		printf("%s`newline'\n", err);
	else if (s[*i + 2] != '<')
		printf("%s`<'\n", err);
	else if (s[*i + 3] != '<')
		printf("%s`<<'\n", err);
	else
		printf("%s`<<<'\n", err);
	return (0);
}

static int	doublera_checker(char *s, int *i, char *err)
{
	if (s[*i + 1] != '>')
		printf("%s`>'\n", err);
	else
		printf("%s`>>'\n", err);
	return (0);
}

static int	redirect_checker(t_list **token_list, char *s, int *i)
{
	t_list	*l;
	t_list	*pl;
	char	*err;

	err = "minishell: syntax error near unexpected token ";
	l = (ft_lstlast(*token_list));
	pl = (ft_lstprelast(*token_list));
	if (l)
	{
		if (((t_tn *)(l->dt))->t_tp == D_RA && s[*i] == '>')
			return (doublera_checker(s, i, err));
		if (((t_tn *)(l->dt))->t_tp == SP && (((t_tn *)(pl->dt))->t_tp == S_RA
			|| ((t_tn *)(pl->dt))->t_tp == S_LA || ((t_tn *)(pl->dt))->t_tp
			== D_RA || ((t_tn *)(pl->dt))->t_tp == D_LA))
		{
			if (s[*i + 1] == s[*i])
				printf("%s`%c%c'\n", err, s[*i], s[*i]);
			else
				printf("%s`%c'\n", err, s[*i]);
			return (0);
		}
		if (((t_tn *)(pl->dt))->t_tp == D_LA && s[*i] == '<')
			return (doublela_checker(s, i, err));
	}
	return (1);
}

int	redirect_lexer(char *line, int *i, t_list **token_list)
{
	t_tn	*t;

	t = (t_tn *)safe_malloc(sizeof(t_tn));
	if (!redirect_checker(token_list, line, i))
	{
		free_token(t);
		return (0);
	}
	ft_straddchar(&t->data, line[(*i)++]);
	if (line[*i - 1] == line[*i])
	{
		if (line[*i] == '<')
			t->t_tp = D_LA;
		else if (line[*i] == '>')
			t->t_tp = D_RA;
		ft_straddchar(&t->data, line[(*i)++]);
	}
	else if (line[*i - 1] == '<')
		t->t_tp = S_LA;
	else if (line[*i - 1] == '>')
		t->t_tp = S_RA;
	ft_lstadd_back(token_list, ft_lstnew(t));
	return (1);
}
