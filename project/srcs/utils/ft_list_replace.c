#include "../../incs/minishell.h"

int	ft_list_replace(t_envp *envp_var, char *old_var, char *new_var)
{
    t_list *temp;
	
	temp = envp_var->envp_list;
	while ((ft_strcmp(temp->content, old_var) != 0) && temp != NULL)
		temp = temp -> next;
	if (temp == NULL)
		ft_lstadd_back(&(envp_var->envp_list), ft_lstnew(new_var));
	else
		temp -> content = new_var;
	return (SUCCESS);
}