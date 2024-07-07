#include "../../incs/minishell.h"

int	ft_list_replace(t_envp *envp_var, char *old_var, char *new_var)
{
    t_list *temp;
	
	temp = envp_var->envp_list;
	while ((ft_strcmp((char *)(temp->content), old_var) != 0) && temp != NULL)
	{
		printf("%s %d\n", __FILE__, __LINE__);
		temp = temp -> next;
	}
	if (temp == NULL)
	{
		printf("%s %d\n", __FILE__, __LINE__);
		ft_lstadd_back(&(envp_var->envp_list), ft_lstnew(new_var));
	}
	else
	{
		printf("%s %d\n", __FILE__, __LINE__);
		temp -> content = new_var;
	}
	return (SUCCESS);
}
