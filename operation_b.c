#include "push_swap.h"

void	ft_pb(t_p_list **head_a, t_p_list **head_b, int flag)
{
	t_p_list	*tmp;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	if (flag == 1)
		ft_putstr_fd("pb\n", 1);
}

void	ft_sb(t_p_list **head_b, int flag)
{
	t_p_list	*tmp;

	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	if (flag == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ft_rb(t_p_list **head_b, int flag)
{
	t_p_list	*tmp;
	t_p_list	*tmp2;
	t_p_list	*tmp3;

	tmp = (*head_b);
	tmp2 = (*head_b);
	tmp3 = (*head_b)->next;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*head_b) = tmp3;
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_p_list **head_b, int flag)
{
	t_p_list	*tmp;
	t_p_list	*tmp2;
	t_p_list	*tmp3;

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
	if (flag == 1)
		ft_putstr_fd("rrb\n", 1);
}
