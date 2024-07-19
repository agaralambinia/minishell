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
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	while (ft_isspace(line[*i]))
	{
		ft_straddchar(&temp->data, line[*i]);
		(*i)++;
	}
	temp->t_tp = SP;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

static void	tild_lexer(char *line, int *i, t_envp *envp_var)
{
	t_tn	*temp;

	if (line[*i + 1] == '/' || ft_isspace(line[*i + 1]) || line[*i + 1] == '\0')
	{
		temp = (t_tn *)safe_malloc(sizeof(t_tn));
		temp->data = ft_strdup("$HOME");
		temp->t_tp = ENVP;
		ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
		(*i)++;
	}
	else
		word_lexer(line, i, envp_var);
}

static void	choose_token(char *line, int *i, t_envp *envp_var, int *res)
{
	if (ft_isspace(line[*i]))
		space_lex(line, i, envp_var);
	else if (line[*i] == '\'' || line[*i] == '\"')
		quote_lexer(line, i, NA, envp_var);
	else if (line[*i] == '>' || line[*i] == '<')
		*res = redirect_lexer(line, i, envp_var);
	else if (line[*i] == '|')
		*res = pipe_lexer(line, i, envp_var);
	else if (line[*i] == '~')
		tild_lexer(line, i, envp_var);
	else
		*res = word_lexer(line, i, envp_var);
}

int	lexer(char *line, t_envp *envp_var)
{
	int	i;	
	int	res;

	i = 0;
	res = 1;
	if (&(envp_var->token_list) && envp_var->token_list)
		ft_lstclear(&envp_var->token_list, &free_token);
	while (line[i] != '\0')
	{
		choose_token(line, &i, envp_var, &res);
		if (!res)
			break ;
	}
	if (res == 1)
	{
		if (envp_var->token_list != NULL)
			tn_clean_null(envp_var->token_list);
		res = token_check(envp_var->token_list);
	}
	return (res);
}
