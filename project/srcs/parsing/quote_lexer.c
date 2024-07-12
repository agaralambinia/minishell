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
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	temp->t_data = (char *)safe_malloc(sizeof(char));
	temp->t_data[0] = 0; 
	temp->token_type = WORD;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	(*i)++;
}

void	fill_content(char q, char *l, int *i, t_envp *envp_var)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	while (!(l[*i] == q || l[*i] == '\0' || (l[*i] == '$' && q == '\"')))
		ft_straddchar(&temp->t_data, l[(*i)++]);
	if (l[*i] == q)
		(*i)++;
	if (q == '\'')
		temp->token_type = HARDWORD;
	else if (q == '\"')
		temp->token_type = SOFTWORD;
	if (temp->t_data)
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
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
		fill_content(q, l, i, envp_var);
	if (l[*i] == '$' && (q == '\"'))
	{
		word_lexer(l, i, envp_var);
		quote_lexer(l, i, DOUBLE, envp_var);
	}
}
