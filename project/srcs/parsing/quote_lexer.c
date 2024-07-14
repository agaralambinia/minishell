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

void	handle_empty_quotes(t_envp *envp_var, int *i)
{
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	temp->data = (char *)safe_malloc(sizeof(char));
	temp->data[0] = 0;
	temp->t_tp = WORD;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	(*i)++;
}

void	fill_data(char q, char *l, int *i, t_envp *envp_var)
{
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	while (!(l[*i] == q || l[*i] == '\0' || (l[*i] == '$' && q == '\"')))
		ft_straddchar(&temp->data, l[(*i)++]);
	if (l[*i] == q)
		(*i)++;
	if (q == '\'')
		temp->t_tp = HARDWORD;
	else if (q == '\"')
		temp->t_tp = SOFTWORD;
	if (temp->data)
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	else
		free(temp);
}

void	quote_lexer(char *l, int *i, t_quote qtype, t_envp *envp_var)
{
	char	q;

	if (l[*i] == l[*i + 1])
	{
		handle_empty_quotes(envp_var, i);
		return ;
	}
	q = '\"';
	if (qtype == NA)
		q = l[(*i)++];
	if (l[(*i)] != '$' || q == '\'')
		fill_data(q, l, i, envp_var);
	if (l[*i] == '$' && (q == '\"'))
	{
		word_lexer(l, i, envp_var);
		quote_lexer(l, i, DOUBLE, envp_var);
	}
}
