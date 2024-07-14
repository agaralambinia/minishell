#include "../../incs/minishell.h"

static int	pipe_checker(t_envp *envp_var, char *line)
{
	t_list	*l;
	t_list	*pl;

	l = (ft_lstlast(envp_var->token_list));
	pl = (ft_lstprelast(envp_var->token_list));
	if (!l && *(line + 1) == '|')
	{
		printf("minishell: syntax error near unexpected token `||'\n");
		return (0);
	}
	if (!l
	|| ((t_token *)(l->content))->token_type == PIPE
	|| (((t_token *)(l->content))->token_type == SPACE
		&& (ft_lstsize(envp_var->token_list) == 1))
	|| (((t_token *)(l->content))->token_type == SPACE
		&& ((t_token *)(pl->content))->token_type == PIPE)
	)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	pipe_lexer(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;

	t = (t_token *)safe_malloc(sizeof(t_token));
	ft_straddchar(&t->t_data, line[(*i)++]);
	if (!pipe_checker(envp_var, line))
	{
		free_token(t);
		return (0);
	}
	t->token_type = PIPE;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(t));
	return (1);
}