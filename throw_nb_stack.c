#include "push_swap.h"

void	ft_order(t_p_list **head_a, int *sort)
{
	t_p_list	*tmp;
	int			i;

	tmp = (*head_a);
	while (tmp != NULL)
	{
		i = 0;
		while (sort[i] != tmp->value)
			i++;
		tmp->order = i + 1;
		tmp = tmp->next;
	}
}

void	from_A_to_B(t_p_list **head_a, t_p_list **head_b, t_var *par)
{
	int	i;

	i = 0;
	while (i < par->mid)
	{
		if ((*head_a)->order <= par->mid)
		{
			(*head_a)->flag++;
			ft_pb(head_a, head_b, 1);
			i++;
		}
		else
			ft_ra(head_a, 1);
	}
}

static int	find_count(int count, t_p_list **head_b, t_var *par)
{
	t_p_list	*tmp;

	tmp = (*head_b);
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->order >= par->mid)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	from_B_to_A(t_p_list **h_a, t_p_list **h_b, t_var *par, int c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	count = find_count(count, h_b, par);
	while (i < count)
	{
		if ((*h_b)->order >= par->mid)
		{
			ft_pa(h_a, h_b, 1);
			(*h_a)->flag = c;
			i++;
		}
		else if ((*h_b)->order == par->next)
		{
			ft_pa(h_a, h_b, 1);
			ft_ra(h_a, 1);
			par->next++;
		}
		else
			ft_rb(h_b, 1);
	}
}

int	ft_find_order(t_p_list **head_a, t_var *par)
{
	t_p_list	*tmp;

	tmp = (*head_a)->next;
	par->c = (*head_a)->order;
	while (tmp != NULL)
	{
		if (tmp->order > par->c)
			par->c = tmp->order;
		tmp = tmp->next;
	}
	return (par->c);
}
