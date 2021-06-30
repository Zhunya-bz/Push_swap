#include "push_swap.h"

void	ft_order(p_list **head_a, int *sort)
{
	p_list	*tmp;
	int		i;

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

void	from_A_to_B(p_list **head_a, p_list **head_b, t_var *par)
{
	int	i;

	i = 0;
	while (i < par->mid)
	{
		if ((*head_a)->order <= par->mid)
		{
			(*head_a)->flag++;
			ft_pb(head_a, head_b);
			i++;
		}
		else
			ft_ra(head_a);
	}
}

static int	find_count(int count, p_list **head_b, t_var *par)
{
	p_list	*tmp;

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

void	from_B_to_A(p_list **head_a, p_list **head_b, t_var *par, int c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	count = find_count(count, head_b, par);
	while (i < count)
	{
		if ((*head_b)->order >= par->mid)
		{
			ft_pa(head_a, head_b);
			(*head_a)->flag = c;
			i++;
		}
		else if ((*head_b)->order == par->next)
		{
			ft_pa(head_a, head_b);
			ft_ra(head_a);
			par->next++;
		}
		else
			ft_rb(head_b);
	}
}

int	ft_find_order(p_list **head_a, t_var *par)
{
	p_list	*tmp;

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
