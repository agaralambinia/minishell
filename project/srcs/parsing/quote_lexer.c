/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:15 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/12 16:05:33 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	handle_empty_quotes(t_list **token_list, int *i, t_tn *temp)
{
	temp->data = (char *)safe_malloc(sizeof(char));
	temp->data[0] = 0;
	temp->t_tp = WORD;
	ft_lstadd_back(token_list, ft_lstnew(temp));
	(*i)++;
}

static void	fill_token(char q, t_list **token_list, t_tn *temp)
{
	if (q == '\"')
		temp->t_tp = SOFTWORD;
	else
		temp->t_tp = HARDWORD;
	ft_lstadd_back(token_list, ft_lstnew(temp));
}

static void	quote_pather(char *l, void **common_data, t_tn *temp, int *i)
{
	fill_token('\"', common_data[0], temp);
	word_lexer(l, i, common_data[1], common_data[0]);
	quote_lexer(l, i, DOUBLE, common_data);
}

void	quote_lexer(char *l, int *i, t_quote qtype, void **common_data)
{
	char	q;
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	q = '\"';
	if (qtype == NA)
		q = l[(*i)++];
	if (l[(*i)] == q)
	{
		handle_empty_quotes(common_data[0], i, temp);
		i++;
		return ;
	}
	while (!(l[(*i)] == q || l[(*i)] == '\0'))
	{
		if (l[(*i)] == '$' && q == '\"')
		{
			quote_pather(l, common_data, temp, i);
			return ;
		}
		else
			ft_straddchar(&temp->data, l[(*i)++]);
	}
	(*i)++;
	fill_token(q, common_data[0], temp);
}
