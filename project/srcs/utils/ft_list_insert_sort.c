#include "../../incs/minishell.h"

static void ft_sort(t_list *newnode, t_list *sorted)
{
    t_list  *current;

    if (sorted == NULL || sorted->content >= newnode->content)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        current = sorted;
        while (current->next != NULL && current->next->content < newnode->content)
            current = current->next;
        newnode->next = current->next;
        current->next = newnode;
    }
}

void ft_list_insert_sort(t_list *lst)
{
    t_list  *temp;
    t_list  *head;
    t_list  *sorted;

    head = NULL;
    sorted = NULL;
    temp = head;
    while (lst != NULL)
    {
        temp = lst->next;
        ft_sort(lst, sorted);
        lst = temp;
    }
    head = sorted;
}
