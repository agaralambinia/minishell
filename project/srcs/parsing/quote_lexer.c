/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:15 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/11 20:28:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	quote_lex(char *l, int *i, t_quote qtype, t_envp *envp_var)
{
	char	q;
	t_token	*temp;

	if (l[*i] == l[*i + 1])
	{
		printf("%s %d\n", __FILE__, __LINE__);
		temp = (t_token *)safe_malloc(sizeof(t_token));
		temp->t_data = (char *)safe_malloc(sizeof(char));
		temp->t_data[0] = 0; 
		temp->token_type = WORD;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
		(*i)++;
		return ;
	}
	q = l[*i];
	i++;
	temp = (t_token *)safe_malloc(sizeof(t_token));
	if (q == '\''')
	{
		while (!(l[*i] == q || l[*i] == '\0'))
			ft_straddchar(&temp->t_data, l[(*i)++]);
		if (l[*i] == q)
			(*i)++;
		temp->token_type = HARDWORD;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	}
	else if (q == '\''')
	{
		while (!(l[*i] == q || l[*i] == '\0'))
		{
 			if (l[*i] == '$')
			{

			}
			ft_straddchar(&temp->t_data, l[(*i)++]);
		}
		if (l[*i] == q)
			(*i)++;
		temp->token_type = HARDWORD;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));

	}

		




	q = '\"';
	if (qtype == NA)
		q = l[(*i)++];
	if (l[(*i)] != '$' || q == '\'')
	{
		temp = (t_token *)safe_malloc(sizeof(t_token));
		while (!(l[*i] == q || l[*i] == '\0' || (l[*i] == '$' && q == '\"')))
			ft_straddchar(&temp->t_data, l[(*i)++]);
		if (l[*i] == q)
			(*i)++;
		if (q == '\'')
			temp->token_type = HARDWORD;
		else if (q == '\"')
			temp->token_type = SOFTWORD;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	}
	if (l[*i] == '$' && (q == '\"'))
	{
		word_lex(l, i, envp_var);
		quote_lex(l, i, DOUBLE, envp_var);
	}
}
