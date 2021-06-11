#include "push_swap.h"

void ft_pb(p_list **head_a, p_list **head_b)
{
	p_list *tmp;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	ft_putstr_fd("pb\n", 1);
}


void ft_sb(p_list **head_b)
{
	p_list *tmp;

	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

void ft_rb(p_list **head_b)
{
	p_list *tmp;
	p_list *tmp2;
	p_list *tmp3;

	tmp = (*head_b);
	tmp2 =(*head_b);
	tmp3 = (*head_b)->next;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*head_b) = tmp3;
	ft_putstr_fd("rb\n", 1);
}

void ft_rrb(p_list **head_b)
{
	p_list *tmp;
	p_list *tmp2;
	p_list *tmp3;

	tmp = (*head_b);
	tmp2 = (*head_b);
	tmp3 = (*head_b);
	while (tmp3->next->next != NULL)
		tmp3 = tmp3->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp3->next = NULL;
	tmp2->next = tmp;
	(*head_b) = tmp2;
	ft_putstr_fd("rrb\n", 1);
}
