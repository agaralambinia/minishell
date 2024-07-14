#include "../../incs/minishell.h"

int	redirect_lexer(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;
	t_list	*last;
	t_list	*prelast;

	t = (t_token *)safe_malloc(sizeof(t_token));
	ft_straddchar(&t->t_data, line[(*i)++]);
	last = (ft_lstlast(envp_var->token_list));
	prelast = (ft_lstprelast(envp_var->token_list));
	// printf("DEBUG %s %d \"%s\" \"%s\"\n", __FILE__, __LINE__, (char *)last->content, (char *)prelast->content);
	if (((t_token *)(last->content))->token_type == SPACE
		&& ((t_token *)(prelast->content))->token_type == SINGLE_RA)
	{
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
		printf("minishell: syntax error near unexpected token `%c'\n", line[*i - 1]);
		free_token(t);
		return (0);
	}
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
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(t));
	return (1);
}