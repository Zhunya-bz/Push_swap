#include "push_swap.h"

void	fill_param(t_var *par, p_list **list_a, p_list **list_b, int argc)
{
	*list_a = NULL;
	*list_b = NULL;
	par->len = 0;
	par->next = 1;
	par->flag = 0;
	par->c = 0;
	par->argc = argc;
}

void	first_step(t_var *par, p_list **list_a, p_list **list_b)
{
	par->max = par->len;
	par->mid = par->max / 2 + par->next;
	from_A_to_B(list_a, list_b, par);
	par->flag++;
	par->size_b = ft_lstsize_p(*list_b);
}

void	throw_stack_B(t_var *par, p_list **list_a, p_list **list_b)
{
	int	c;

	c = 1;
	par->size_b = ft_lstsize_p(*list_b);
	while (par->size_b > 3)
	{
		par->max = ft_find_order(list_b, par);
		par->mid = (par->max - par->next) / 2 + par->next;
		from_B_to_A(list_a, list_b, par, c);
		par->size_b = ft_lstsize_p(*list_b);
		c++;
	}
	par->flag = c;
}

void	ft_check_top_bottom(t_var *par, p_list **list_a, p_list **list_b)
{
	int	i;
	int	k;

	par->size_b = ft_lstsize_p(*list_b);
	while (par->size_b > 3)
	{
		i = 0;
		k = check_top_bottom(list_b, par);
		if (k <= par->size_b / 2)
			while (i++ < k)
				ft_rb(list_b);
		else
			while (i++ < par->size_b - k)
				ft_rrb(list_b);
		if ((*list_b)->order == par->next)
		{
			ft_pa(list_a, list_b);
			ft_ra(list_a);
			par->next++;
			par->size_b--;
		}
	}
}

int	general_cycle(t_var *par, p_list **list_a, p_list **list_b)
{
	while (!(if_sort_list(list_a) && list_b == NULL))
	{
		par->size_b = ft_lstsize_p(*list_b);
		if (par->flag == 0)
		{
			throw_stack_B(par, list_a, list_b);
			check_size_b_3(par, list_a, list_b);
			check_size_b_2(par, list_a, list_b);
			check_size_b_1(par, list_a, list_b);
			if (if_sort_list(list_a))
				return (0);
			check_flags_stack(par, list_a, list_b);
		}
		ft_check_top_bottom(par, list_a, list_b);
		check_first_2_A(par, list_a);
		check_size_b_3(par, list_a, list_b);
		check_size_b_2(par, list_a, list_b);
		check_size_b_1(par, list_a, list_b);
		if (if_sort_list(list_a))
			return (0);
		check_flags_stack(par, list_a, list_b);
	}
	return (1);
}
