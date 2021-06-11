#include "push_swap.h"

void ft_pa(p_list **head_a, p_list **head_b)
{
	p_list *tmp;

	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	ft_putstr_fd("pa\n", 1);
}

void ft_sa(p_list **head_a)
{
	p_list *tmp;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

void ft_ra(p_list **head_a)
{
	p_list *tmp;
	p_list *tmp2;
	p_list *tmp3;

	tmp = (*head_a);
	tmp2 =(*head_a);
	tmp3 = (*head_a)->next;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*head_a) = tmp3;
	ft_putstr_fd("ra\n", 1);
}

void ft_rra(p_list **head_a)
{
	p_list *tmp;
	p_list *tmp2;
	p_list *tmp3;

	tmp = (*head_a);
	tmp2 = (*head_a);
	tmp3 = (*head_a);
	while (tmp3->next->next != NULL)
		tmp3 = tmp3->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp3->next = NULL;
	tmp2->next = tmp;
	(*head_a) = tmp2;
	ft_putstr_fd("rra\n", 1);
}

