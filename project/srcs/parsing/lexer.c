/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:20:17 by defimova          #+#    #+#             */
/*   Updated: 2024/06/21 20:55:24 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	space_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	while (ft_isspace(line[*i]))
	{
		temp->token_content = ft_straddchar(temp->token_content, line[*i]);
		(*i)++;
	}
	temp->token_type = SPACE;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

static void	word_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	if (line[*i] == '$')
	{
		temp->token_type = ENVP;
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	}
	else
		temp->token_type = WORD;
	while (line[*i] != '\0' && !ft_isspace(line[*i]) && !ft_isspecial(line[*i]))
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

static void	quote_lex(char *l, int *i, t_quote qtype, t_envp *envp_var)
{
	char	q;
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	if (qtype == NA)
		q = l[(*i)++];
	else
		q = '\"';
	while (!(l[*i] == q || l[*i] == '\0' || (l[*i] == '$' && q == '\"')))
		temp->token_content = ft_straddchar(temp->token_content, l[(*i)++]);
	if (l[*i] == q)
		(*i)++;
	if (q == '\'')
		temp->token_type = HARDWORD;
	else if (q == '\"')
		temp->token_type = SOFTWORD;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	if (l[*i] == '$' && temp->token_type == SOFTWORD)
	{
		word_lex(l, i, envp_var);
		quote_lex(l, i, DOUBLE, envp_var);
	}
}

static void	redirpipe_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;

	t = (t_token *)safe_malloc(sizeof(t_token));
	t->token_content = ft_straddchar(t->token_content, line[(*i)++]);
	if ((line[*i - 1] == '<' || line[*i - 1] == '>'))
	{
		if (line[*i - 1] == line[*i])
		{
			if (line[*i] == '<')
				t->token_type = DOUBLE_LA;
			else if (line[*i] == '>')
				t->token_type = DOUBLE_RA;
			t->token_content = ft_straddchar(t->token_content, line[(*i)++]);
		}
		else if (line[*i - 1] == '<')
			t->token_type = SINGLE_LA;
		else if (line[*i - 1] == '>')
			t->token_type = SINGLE_RA;
	}
	else if (line[*i - 1] == '|')
		t->token_type = PIPE;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(t));
}

void	lexer(char *line, t_envp *envp_var)
{
	int	i;

	i = 0;
	ft_lstclear(&envp_var->token_list, free);
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			space_lex(line, &i, envp_var);
		else if (line[i] == '\'' || line[i] == '\"')
			quote_lex(line, &i, NA, envp_var);
		else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			redirpipe_lex(line, &i, envp_var);
		else
			word_lex(line, &i, envp_var);
	}
}
