#include "../../incs/minishell.h"

void	tn_clean_null(t_list *lst)
{
	t_list	*iter;
	t_list	*temp;

	iter = lst;
	while (iter != NULL)
	{
		if (iter->next != NULL && iter->next->dt != NULL
			&& ((t_tn *)(iter->next->dt))->data == NULL)
		{
			if ((iter->next)->next != NULL && (iter->next->next)->dt != NULL
					&& (iter->next->next)->next != NULL)
			{
				temp = (t_list *)safe_malloc(sizeof(t_list));
				temp->dt = (iter->next->next)->dt;
				temp->next = (iter->next->next)->next;
				ft_lstdelone(iter->next, &free);
				iter->next = temp;
			}
			else
			{
				ft_lstdelone(iter->next, &free);
				iter->next = NULL;
			}
		}
		iter = iter -> next;
	}
}
