#include "push_swap.h"

void ft_ss(p_list **head_a, p_list **head_b)
{
	p_list *tmp;
	p_list *tmp2;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;

	tmp2 = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp2->next = (*head_b)->next;
	(*head_b)->next = tmp2;
	ft_putstr_fd("ss\n", 1);
}

void ft_rr(p_list **head_a, p_list **head_b)
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
	ft_putstr_fd("rr\n", 1);
}

void ft_rrr(p_list **head_a, p_list **head_b)
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
	ft_putstr_fd("rrr\n", 1);
}