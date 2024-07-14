#include "../../incs/minishell.h"

static int	doublela_checker(char *s, int *i, char *err)
{
	if (s[*i + 1] != '<')
		printf("%s`newline'\n", err);
	else if (s[*i + 2] != '<')
		printf("%s`<'\n", err);
	else if (s[*i + 3] != '<')
		printf("%s`<<'\n", err);
	else
		printf("%s`<<<'\n", err);
	return (0);
}

static int	doublera_checker(char *s, int *i, char *err)
{
	if (s[*i + 1] != '>')
		printf("%s`>'\n", err);
	else
		printf("%s`>>'\n", err);
	return (0);
}

static int	redirect_checker(t_envp *envp_var, char *s, int *i)
{
	t_list	*l;
	t_list	*pl;
	char	*err;

	err = "minishell: syntax error near unexpected token ";
	l = (ft_lstlast(envp_var->token_list));
	pl = (ft_lstprelast(envp_var->token_list));
	if (l)
	{
		if (((t_token *)(l->content))->token_type == D_RA && s[*i] == '>')
			return(doublera_checker(s, i, err));
		if (((t_token *)(l->content))->token_type == SPACE
			&& (((t_token *)(pl->content))->token_type == SINGLE_RA
			|| ((t_token *)(pl->content))->token_type == SINGLE_LA
			|| ((t_token *)(pl->content))->token_type == D_RA
			|| ((t_token *)(pl->content))->token_type == D_LA))
		{
			if (s[*i + 1] == s[*i])
				printf("%s`%c%c'\n", err, s[*i], s[*i]);
			else
				printf("%s`%c'\n", err, s[*i]);
			return (0);
		}
		if (((t_token *)(pl->content))->token_type == D_LA && s[*i] == '<')
			return(doublela_checker(s, i, err));
	}
	return (1);
}

int	redirect_lexer(char *line, int *i, t_envp *envp_var)
{
	t_token	*t;

	t = (t_token *)safe_malloc(sizeof(t_token));
	if (!redirect_checker(envp_var, line, i))
	{
		free_token(t);
		return (0);
	}
	ft_straddchar(&t->t_data, line[(*i)++]);
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (line[*i - 1] == line[*i])
	{
		if (line[*i] == '<')
			t->token_type = D_LA;
		else if (line[*i] == '>')
			t->token_type = D_RA;
		ft_straddchar(&t->t_data, line[(*i)++]);
	}
	else if (line[*i - 1] == '<')
		t->token_type = SINGLE_LA;
	else if (line[*i - 1] == '>')
		t->token_type = SINGLE_RA;
	ft_lstadd_back(&(envp_var->token_list), ft_lstnew(t));
	return (1);
}