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

static void	space_lex(char *line, int *i, t_list **token_list)
{
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	while (ft_isspace(line[*i]))
	{
		ft_straddchar(&temp->data, line[*i]);
		(*i)++;
	}
	temp->t_tp = SP;
	ft_lstadd_back(token_list, ft_lstnew(temp));
}

static void	tild_lexer(char *line, int *i, t_envp *envp_var, t_list **token_list)
{
	t_tn	*temp;

	if (line[*i + 1] == '/' || ft_isspace(line[*i + 1]) || line[*i + 1] == '\0')
	{
		temp = (t_tn *)safe_malloc(sizeof(t_tn));
		temp->data = ft_strdup("$HOME");
		temp->t_tp = ENVP;
		ft_lstadd_back(token_list, ft_lstnew(temp));
		(*i)++;
	}
	else
		word_lexer(line, i, envp_var, token_list);
}

static void	choose_token(
	char *line, t_list **token_list, t_envp *envp_var, int **proc_data)
{
	int	*i;	
	int	*res;
	void	*common_data[2];

	i = proc_data[0]; 
	res = proc_data[1]; 
	common_data[0] = token_list;
	common_data[1] = envp_var;
	if (ft_isspace(line[*i]))
		space_lex(line, i, token_list);
	else if (line[*i] == '\'' || line[*i] == '\"')
		quote_lexer(line, i, NA, common_data);
	else if (line[*i] == '>' || line[*i] == '<')
		*res = redirect_lexer(line, i, token_list);
	else if (line[*i] == '|')
		*res = pipe_lexer(line, i, token_list);
	else if (line[*i] == '~')
		tild_lexer(line, i, envp_var, token_list);
	else
		*res = word_lexer(line, i, envp_var, token_list);
}

int	lexer(char **line, t_list **token_list, t_envp *envp_var)
{
	int	i;	
	int	res;
	int	*proc_data[2];

	i = 0;
	res = 1;
	proc_data[0] = &i;
	proc_data[1] = &res;
	while ((*line)[i] != '\0')
	{
		choose_token(*line, token_list, envp_var, proc_data);
		if (!res)
			break ;
	}
	if (res == 1)
	{
		if (token_list != NULL)
			tn_clean_null(token_list);
		res = token_check(token_list, envp_var, line);
		if (!res && token_list && *token_list)
			ft_lstclear(token_list, &free_token);
	}
	return (res);
}
