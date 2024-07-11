/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:20:17 by defimova          #+#    #+#             */
/*   Updated: 2024/07/11 20:28:23 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	space_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	while (ft_isspace(line[*i]))
	{
		ft_straddchar(&temp->t_data, line[*i]);
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
		if (line[*i + 1] == '?')
		{
			temp->token_type = EXITSTATUS;
			(*i) += 2;
			ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
			word_lex(line, i, envp_var);
			return ;
		}
		else
		{
			temp->token_type = ENVP;
			ft_straddchar(&temp->t_data, line[(*i)++]);
		}
	}
	else
		temp->token_type = WORD;
	if (line[*i] == '/')
		ft_straddchar(&temp->t_data, line[(*i)++]);
	while (line[*i] != '\0' && !ft_isspace(line[*i]) && !ft_isspecial(line[*i]))
	{
		if (line[*i] == '/')
			break;
		ft_straddchar(&temp->t_data, line[(*i)++]);
	}
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

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

static void	redirpipe_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;

	t = (t_token *)safe_malloc(sizeof(t_token));
	ft_straddchar(&t->t_data, line[(*i)++]);
	if ((line[*i - 1] == '<' || line[*i - 1] == '>'))
	{
		if (line[*i - 1] == line[*i])
		{
			if (line[*i] == '<')
				t->token_type = DOUBLE_LA;
			else if (line[*i] == '>')
				t->token_type = DOUBLE_RA;
			ft_straddchar(&t->t_data, line[(*i)++]);
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

static void tild_lexer(char *line, int *i, t_envp *envp_var)
{
	t_token	*temp;

	if (line[*i + 1] == '/' || ft_isspace(line[*i + 1]) || line[*i + 1] == '\0')
	{
		temp = (t_token *)safe_malloc(sizeof(t_token));
		temp->t_data = ft_strdup("$HOME");
		temp->token_type = ENVP;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
		(*i)++;
	}
	else
		word_lex(line, i, envp_var);
}

void	lexer(char *line, t_envp *envp_var)
{
	int	i;	

	i = 0;
	if (&(envp_var->token_list) && envp_var->token_list)
		ft_lstclear(&envp_var->token_list, &free_token);
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			space_lex(line, &i, envp_var);
		else if (line[i] == '\'' || line[i] == '\"')
			quote_lex(line, &i, NA, envp_var);
		else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			redirpipe_lex(line, &i, envp_var);
		else if (line[i] == '~')
			tild_lexer(line, &i, envp_var);
		else
			word_lex(line, &i, envp_var);
	}
}
