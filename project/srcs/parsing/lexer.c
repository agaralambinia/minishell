/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:20:17 by defimova          #+#    #+#             */
/*   Updated: 2024/07/12 16:00:54 by sosokin          ###   ########.fr       */
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

static void	redirpipe_lex(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;
	t_list	*last;

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
	{
		last = (ft_lstlast(envp_var->token_list));
		if (!last || ((t_token *)(last->content))->token_type == PIPE){
			printf("minishell: syntax error near unexpected token '|'\n");
			free(t);
			return ;
		}
		t->token_type = PIPE;
	}
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
		word_lexer(line, i, envp_var);
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
			quote_lexer(line, &i, NA, envp_var);
		else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			redirpipe_lex(line, &i, envp_var);
		else if (line[i] == '~')
			tild_lexer(line, &i, envp_var);
		else
			word_lexer(line, &i, envp_var);
	}
	//system("leaks minishell");
}
