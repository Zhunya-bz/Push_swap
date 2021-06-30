#include <stdio.h>
#include "push_swap.h"

void print_list(p_list **lst1, p_list **lst2) /// !!! DELETE !!!
{
	p_list *tmp;

	tmp = (*lst1);
	printf("A:\n");
	while (tmp != NULL)
	{
		printf("value = %d   ", tmp->value);
		printf("order = %d   ", tmp->order);
		printf("flag = %d\n", tmp->flag);
		tmp = tmp->next;
	}
	tmp = (*lst2);
	printf("B:\n");
	while (tmp != NULL)
	{
		printf("value = %d   ", tmp->value);
		printf("order = %d   ", tmp->order);
		printf("flag = %d\n", tmp->flag);
		tmp = tmp->next;
	}
}

static void	fill_param(t_var *par, p_list **list_a, p_list **list_b, int argc)
{
	*list_a = NULL;
	*list_b = NULL;
	par->len = 0;
	par->next = 1;
	par->flag = 0;
	par->c = 0;
	par->argc = argc;
}

static int check_2_nb(t_var *par, p_list **list_a)
{
	par->size_a = ft_lstsize_p(*list_a);
	if (par->size_a == 2) // на 2 числа
	{
		if (par->size_a == 2)
		{
			if ((*list_a)->order != par->next)
			{
				ft_ra(list_a);
				par->next++;
			}
		}
		return (0);
	}
	return (1);
}

static void first_step(t_var *par, p_list **list_a, p_list **list_b)
{
	par->max = par->len;
	par->mid = par->max / 2 + par->next;
	from_A_to_B(list_a, list_b, par);
	par->flag++;
	par->size_b = ft_lstsize_p(*list_b);
}

static void throw_stack_B(t_var *par, p_list **list_a, p_list **list_b)
{
	int c;

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

static void check_size_b_3(t_var *par, p_list **list_a, p_list **list_b)
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

static void check_size_b_2(t_var *par, p_list **list_a, p_list **list_b)
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

static void check_first_2_A(t_var *par, p_list **list_a)
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

static void check_size_b_1(t_var *par, p_list **list_a, p_list **list_b)
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

static void check_flags_stack(t_var *par, p_list **list_a, p_list **list_b)
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

static void ft_check_top_bottom(t_var *par, p_list **list_a, p_list **list_b)
{
	int i;
	int k;

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
static int general_cycle(t_var *par, p_list **list_a, p_list **list_b)
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
		check_first_2_A(par, list_a);check_size_b_3(par, list_a, list_b);
		check_size_b_2(par, list_a, list_b);
		check_size_b_1(par, list_a, list_b);
		if (if_sort_list(list_a))
			return (0);
		check_flags_stack(par, list_a, list_b);
	}
	return (1);
}

static int	check_sort(int *a, t_var *par, int *sort, p_list **list_a)
{
	if (if_sort(a, 0, par->len))
	{
		free(a);
		free(sort);
		return (0);
	}
	sort = ft_sorted(sort, a, par->len);
	ft_order(list_a, sort);
	free(a);
	free(sort);
	return (1);
}

static int argument(int argc, char **argv, t_var *par, p_list **list_a)
{
	int *a;
	int *sort;

	a = ft_calloc((2 * argc), (sizeof(int)));
	sort = ft_calloc((2 * argc), (sizeof(int)));
	if (!a || !sort)
		return (0);
	if (argc == 2)
	{
		if (!check_string(argv, par, list_a, a))
		{
			free(sort);
			return (0);
		}
	}
	else
		if (!check_argument(argv, par, list_a, a))
		{
			free(sort);
			return (0);
		}
	if (!check_sort(a, par, sort, list_a))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int *a;
	int *sort;
	p_list *list_a;
	p_list *list_b;
	t_var par;

	fill_param(&par, &list_a, &list_b, argc);
	if (argc > 1)
	{
		if (!argument(argc, argv, &par, &list_a))
			return (0);
		if (!check_2_nb(&par, &list_a))
			return (0);
		first_step(&par, &list_a, &list_b);
		throw_stack_B(&par, &list_a, &list_b);
		check_size_b_3(&par, &list_a, &list_b);
		check_size_b_2(&par, &list_a, &list_b);
		check_size_b_1(&par, &list_a, &list_b);
		if (if_sort_list(&list_a))
			return (0);
		check_flags_stack(&par, &list_a, &list_b);
		if (!general_cycle(&par, &list_a, &list_b))
			return (0);
	}
}
