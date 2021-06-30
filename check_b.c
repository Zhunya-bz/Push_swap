#include "push_swap.h"

void check_size_b_3(t_var *par, p_list **list_a, p_list **list_b)
{
	if (par->size_b == 3)
	{
		while ((*list_b)->order != par->next)
			ft_rb(list_b);
		if ((*list_b)->order == par->next)
		{
			ft_pa(list_a, list_b);
			ft_ra(list_a);
			par->next++;
			par->size_b--;
		}
	}
}

void check_size_b_2(t_var *par, p_list **list_a, p_list **list_b)
{
	if (par->size_b == 2)
	{
		if ((*list_b)->order == par->next)
		{
			ft_pa(list_a, list_b);
			ft_ra(list_a);
			par->next++;
			par->size_b--;
		}
		else if ((*list_b)->next->order == par->next)
		{
			ft_sb(list_b);
			ft_pa(list_a, list_b);
			ft_ra(list_a);
			par->next++;
			par->size_b--;
		}
		else
		{
			ft_pa(list_a, list_b);
			ft_pa(list_a, list_b);
			par->size_b -= 2;
		}
	}
}

void check_first_2_A(t_var *par, p_list **list_a)
{
	if ((*list_a)->next->order == par->next)
	{
		ft_sa(list_a);
		ft_ra(list_a);
		par->next++;
	}
	while ((*list_a)->order == par->next)
	{
		ft_ra(list_a);
		par->next++;
	}
}

void check_size_b_1(t_var *par, p_list **list_a, p_list **list_b)
{
	if (par->size_b == 1)
	{
		if ((*list_b)->order == par->next)
		{
			ft_pa(list_a, list_b);
			ft_ra(list_a);
			par->next++;
		}
		else
			ft_pa(list_a, list_b);
	}
	check_first_2_A(par, list_a);
}

void check_flags_stack(t_var *par, p_list **list_a, p_list **list_b)
{
	par->c = 0;
	while (par->flag >= 0)
	{
		while (((*list_a)->flag == par->flag) && (*list_a)->order != 1)
		{
			ft_pb(list_a, list_b);
			par->c = 1;
		}
		if (par->c == 1)
			break;
		par->flag--;
	}
}
