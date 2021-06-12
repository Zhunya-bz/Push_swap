#include "push_swap.h"

p_list	*ft_lstnew_p(int content)
{
	p_list	*new_el;

	new_el = (p_list *)malloc(sizeof(p_list));
	if (!new_el)
		return (NULL);
	new_el->value = content;
	new_el->order = 0;
	new_el->flag = 0;
	new_el->next = NULL;
	return (new_el);
}

int	ft_lstsize_p(p_list *lst)
{
	int		count;
	p_list	*copy_lst;

	count = 0;
	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst != NULL)
	{
		count++;
		copy_lst = copy_lst->next;
	}
	return (count);
}

void	ft_lstadd_back_p(p_list **lst, p_list *new)
{
	p_list	*last_el;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last_el = ft_lstlast_p(*lst);
		last_el->next = new;
	}
}
