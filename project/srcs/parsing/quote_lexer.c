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

void	quote_lexer(char *l, int *i, t_quote qtype, void **common_data)
{
	char	q;
	t_tn	*temp;
	t_list **token_list; 
	t_envp *envp_var;

	token_list = common_data[0];
	envp_var = common_data[1];
	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	q = '\"';
	if (qtype == NA)
		q = l[(*i)++];
	//printf("DEBUG <%c> %s\n", q, __FILE__); //TODO убрать
	if (l[(*i)] == q)
	{
		handle_empty_quotes(token_list, i, temp);
		i++;
		return ;
	}
	while (!(l[(*i)] == q || l[(*i)] == '\0'))
	{
		if (l[(*i)] == '$' && q == '\"')
		{
			fill_token(q, token_list, temp);
			word_lexer(l, i, envp_var, token_list);
			quote_lexer(l, i, DOUBLE, common_data);
			return ;
		}
		else
			ft_straddchar(&temp->data, l[(*i)++]);
	}
	(*i)++;
	fill_token(q, token_list, temp);
}
