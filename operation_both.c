#include "push_swap.h"

void	ft_ss(t_p_list **head_a, t_p_list **head_b, int flag)
{
	t_p_list	*tmp;
	t_p_list	*tmp2;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	tmp2 = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp2->next = (*head_b)->next;
	(*head_b)->next = tmp2;
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_p_list **head_a, t_p_list **head_b, int flag)
{
	t_p_list	*tmp;
	t_p_list	*tmp2;
	t_p_list	*tmp3;

	tmp = (*head_a);
	tmp2 = (*head_a);
	tmp3 = (*head_a)->next;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*head_a) = tmp3;
	tmp = (*head_b);
	tmp2 = (*head_b);
	tmp3 = (*head_b)->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*head_b) = tmp3;
	if (flag == 1)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_p_list **head_a, t_p_list **head_b, int flag)
{
	ft_rra(head_a, 0);
	ft_rrb(head_b, 0);
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
}
