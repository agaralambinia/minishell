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

static void	handle_exit_code(
	t_tn *temp, t_envp *envp_var, t_list **token_list, int *i)
{
	temp->t_tp = EXITSTATUS;
	temp->data = ft_itoa(envp_var->last_code);
	(*i) += 2;
	ft_lstadd_back(token_list, ft_lstnew(temp));
}

static void	handle_envp(t_tn *temp, char *line, int *i)
{
	temp->t_tp = ENVP;
	ft_straddchar(&temp->data, line[(*i)++]);
}

static void	fill_data(char *line, int *i, t_tn *temp)
{
	if (line[*i] == '/' || line[*i] == '=')
		ft_straddchar(&temp->data, line[(*i)++]);
	while (line[*i] != '\0' && !ft_isspace(line[*i]) && !ft_isspecial(line[*i]))
	{
		if (line[*i] == '/' || line[*i] == '=')
			break ;
		ft_straddchar(&temp->data, line[(*i)++]);
	}
}

int	word_lexer(char *line, int *i, t_envp *envp_var, t_list **token_list)
{
	t_tn	*temp;

	temp = (t_tn *)safe_malloc(sizeof(t_tn));
	if (line[*i] == '$')
	{
		if (line[*i + 1] == '?')
		{
			handle_exit_code(temp, envp_var, token_list, i);
			return (1);
		}
		else if (ft_isdigit(line[*i + 1]))
		{
			temp->t_tp = WORD;
			(*i) += 2;
		}
		else
			handle_envp(temp, line, i);
	}
	else
		temp->t_tp = WORD;
	fill_data(line, i, temp);
	ft_lstadd_back(token_list, ft_lstnew(temp));
	return (1);
}
