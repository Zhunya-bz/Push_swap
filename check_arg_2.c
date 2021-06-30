#include "push_swap.h"

int	check_2_nb(t_var *par, p_list **list_a)
{
	par->size_a = ft_lstsize_p(*list_a);
	if (par->size_a == 2)
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

int	check_sort(int *a, t_var *par, p_list **list_a)
{
	int	*sort;

	sort = NULL;
	if (if_sort(a, 0, par->len))
	{
		free(a);
		return (0);
	}
	sort = ft_sorted(sort, a, par->len);
	ft_order(list_a, sort);
	free(a);
	free(sort);
	return (1);
}

int	argument(int argc, char **argv, t_var *par, p_list **list_a)
{
	int	*a;

	a = ft_calloc((2 * argc), (sizeof(int)));
	if (!a)
		return (0);
	if (argc == 2)
	{
		if (!check_string(argv, par, list_a, a))
			return (0);
	}
	else
	{
		if (!check_argument(argv, par, list_a, a))
			return (0);
	}
	if (!check_sort(a, par, list_a))
		return (0);
	return (1);
}
