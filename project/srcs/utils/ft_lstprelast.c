#include "../../incs/minishell.h"

t_list	*ft_lstprelast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (lst == NULL)
		return (lst);
	while (last->next != NULL && last->next->next != NULL)
		last = last->next;
	return (last);
}