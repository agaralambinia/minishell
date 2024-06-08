/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:20:17 by defimova          #+#    #+#             */
/*   Updated: 2024/06/06 20:20:19 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	space_lex(char *line, int *i)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token *));
	while (ft_isspace(line[*i]))
	{
		temp->token_content = ft_straddchar(temp->token_content, line[*i]);
		(*i)++;
	}
	temp->token_type = SPACE;
	ft_lstadd_back(&(g_envp->token_list), ft_lstnew(temp));
}

static void	quote_lex(char *line, int *i)
{
	char	quote;
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token *));
	quote = line[*i];
	temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	while ((!(line[*i] == quote) || line[*i] == '\0'))
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	if (line[*i] == quote)
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	if (quote == '\'')
		temp->token_type = HARDWORD;
	else if (quote == '\"')
		temp->token_type = SOFTWORD;
	ft_lstadd_back(&(g_envp->token_list), ft_lstnew(temp));
}

static void	redirpipe_lex(char *line, int *i)
{
	t_token	*t;

	t = (t_token *)safe_malloc(sizeof(t_token *));
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
	ft_lstadd_back(&(g_envp->token_list), ft_lstnew(t));
}

static void	word_lex(char *line, int *i)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token *));
	if (line[*i] == '$')
	{
		temp->token_type = ENVP;
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	}
	else
		temp->token_type = WORD;
	while (line[*i] != '\0' && !ft_isspace(line[*i]) && !ft_isspecial(line[*i]))
		temp->token_content = ft_straddchar(temp->token_content, line[(*i)++]);
	ft_lstadd_back(&(g_envp->token_list), ft_lstnew(temp));
}

void	lexer(char *line)
{
	int	i;

	i = 0;
	ft_lstclear(&g_envp->token_list, free);
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			space_lex(line, &i);
		else if (line[i] == '\'' || line[i] == '\"')
			quote_lex(line, &i);
		else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			redirpipe_lex(line, &i);
		else
			word_lex(line, &i);
	}
}
