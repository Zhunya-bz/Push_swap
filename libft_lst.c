#include "push_swap.h"

t_p_list 	*ft_lstlast_p(t_p_list *lst)
{
	t_p_list	*copy_lst;

	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst->next != NULL)
	{
		copy_lst = copy_lst->next;
	}
	return (copy_lst);
}

t_p_list 	*ft_lstnew_p(int content)
{
	t_p_list	*new_el;

	new_el = (t_p_list *)malloc(sizeof(t_p_list));
	if (!new_el)
		return (NULL);
	new_el->value = content;
	new_el->order = 0;
	new_el->flag = 0;
	new_el->next = NULL;
	return (new_el);
}

int	ft_lstsize_p(t_p_list *lst)
{
	int			count;
	t_p_list	*copy_lst;

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

void	ft_lstadd_back_p(t_p_list **lst, t_p_list *new)
{
	t_p_list	*last_el;

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

void	clear_list(t_p_list **lst)
{
	t_p_list	*tmp;
	t_p_list	*tmp2;

	tmp = *lst;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	tmp = tmp->next;
	free(tmp);
	*lst = NULL;
}
