#include "push_swap.h"

static void par_3_v(t_p_list **list_a)
{
	if (if_sort_list(list_a))
		return ;
	else
	{
		ft_ra(list_a, 1);
		ft_ra(list_a, 1);
		ft_sa(list_a, 1);
	}
}

static void param_3(t_var *par, t_p_list **list_a)
{
	par->max = par->len;
	par->mid = par->max / 2 + par->next;
	if ((*list_a)->order > par->mid)
	{
		ft_ra(list_a, 1);
		if (if_sort_list(list_a))
			return ;
		else
			ft_sa(list_a, 1);
	}
	else if ((*list_a)->order == par->mid)
	{
		ft_sa(list_a, 1);
		if (if_sort_list(list_a))
			return ;
		else
		{
			ft_ra(list_a, 1);
			ft_sa(list_a, 1);
		}
	}
	else
		par_3_v(list_a);
}

static void param_4(t_var *par, t_p_list **list_a, t_p_list **list_b)
{
	int i;

	i = 1;
	par->max = par->len;
	par->mid = par->max / 2 + par->next;
	while (i < par->mid)
	{
		if ((*list_a)->order < par->mid)
		{
			ft_pb(list_a, list_b, 1);
			i++;
		} else
			ft_ra(list_a, 1);
	}
	if (!if_sort_list(list_a))
		ft_sa(list_a, 1);
	if (if_sort_list(list_b))
		ft_sb(list_b, 1);
	ft_pa(list_a, list_b, 1);
	ft_pa(list_a, list_b, 1);
}

static void param_5(t_var *par, t_p_list **list_a, t_p_list **list_b)
{
	int i;

	i = 1;
	par->max = par->len;
	par->mid = par->max / 2 + par->next;
	while (i < par->mid)
	{
		if ((*list_a)->order < par->mid)
		{
			ft_pb(list_a, list_b, 1);
			i++;
		}
		else
			ft_ra(list_a, 1);
	}
	par->len += 2;
	param_3(par, list_a);
	if (if_sort_list(list_b))
		ft_sb(list_b, 1);
	ft_pa(list_a, list_b, 1);
	ft_pa(list_a, list_b, 1);
}

void few_par(int argc, t_var *par, t_p_list **list_a, t_p_list **list_b)
{
	if (argc == 4)
		param_3(par, list_a);
	else if (argc == 5)
		param_4(par, list_a, list_b);
	else if (argc == 6)
		param_5(par, list_a, list_b);
}

