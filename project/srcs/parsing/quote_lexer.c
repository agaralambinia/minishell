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

static void	handle_empty_quotes(t_envp *envp_var, int *i, t_tn *temp)
{
	temp->data = (char *)safe_malloc(sizeof(char));
	temp->data[0] = 0;
	temp->t_tp = WORD;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	(*i)++;
}

static void	fill_token(char q, t_envp *envp_var, t_tn *temp)
{
	if (q == '\"')
		temp->t_tp = SOFTWORD;
	else
		temp->t_tp = HARDWORD;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

void	quote_lexer(char *l, int *i, t_quote qtype, t_envp *envp_var)
{
	char	q;
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	q = '\"';
	if (qtype == NA)
		q = l[(*i)++];
	//printf("DEBUG <%c> %s\n", q, __FILE__); //TODO убрать
	if (l[(*i)] == q)
	{
		handle_empty_quotes(envp_var, i, temp);
		i++;
		return ;
	}
	while (!(l[(*i)] == q || l[(*i)] == '\0'))
	{
		if (l[(*i)] == '$' && q == '\"')
		{
			fill_token(q, envp_var, temp);
			word_lexer(l, i, envp_var);
			quote_lexer(l, i, DOUBLE, envp_var);
			return ;
		}
		else
			ft_straddchar(&temp->data, l[(*i)++]);
	}
	(*i)++;
	fill_token(q, envp_var, temp);
}
