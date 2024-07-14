/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:37:38 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/12 17:46:59 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	handle_exit_code(t_token *temp, t_envp *envp_var, int *i)
{
	temp->token_type = EXITSTATUS;
	temp->t_data = ft_itoa(envp_var->last_code); 
	(*i) += 2;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
}

static void	handle_envp(t_token *temp, char *line, int *i)
{
	temp->token_type = ENVP;
	ft_straddchar(&temp->t_data, line[(*i)++]);
}

static void	fill_content(char *line, int *i, t_token *temp)
{
	if (line[*i] == '/' || line[*i] == '=')
		ft_straddchar(&temp->t_data, line[(*i)++]);
	while (line[*i] != '\0' && !ft_isspace(line[*i]) && !ft_isspecial(line[*i]))
	{
		if (line[*i] == '/' || line[*i] == '=')
			break;
		ft_straddchar(&temp->t_data, line[(*i)++]);
	}
}

// static int	word_checker(t_envp *envp_var, char *word)
// {
	// t_list	*l;
// 
	// l = (ft_lstlast(envp_var->token_list));
	// if (!l)
	// {
		// printf("minishell: %s: command not found\n", word);
		// return (0);
	// }
	// return (1);
// }

int	word_lexer(char *line, int *i, t_envp *envp_var)
{
	t_token	*temp;

	temp = (t_token *)safe_malloc(sizeof(t_token));
	if (line[*i] == '$')
	{
		if (line[*i + 1] == '?')
		{
			handle_exit_code(temp, envp_var, i);
			return (1);
		}
		else if (ft_isdigit(line[*i + 1]))
		{
			temp->token_type = WORD;
			(*i) += 2;
		}
		else
			handle_envp(temp, line, i);
	}
	else
		temp->token_type = WORD;
	fill_content(line, i, temp);
	//if (temp->token_type == WORD && !word_checker(envp_var, temp->t_data))
	//{
	//	free_token(temp);
	//	return (0);
	//}
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(temp));
	return (1);
}
