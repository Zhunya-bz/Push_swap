#include "push_swap.h"

static int	check_double(int i, int *a)
{
	int	k;

	k = 0;
	while (k < i - 1)
	{
		if (a[k] == a[i - 1])
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		k++;
	}
	return (1);
}

int	check_argument(char **argv, t_var *par, t_p_list **list_a, int *a)
{
	int	i;

	i = 1;
	while (i < par->argc)
	{
		if (!read_argv(argv, i, par))
		{
			free(a);
			return (0);
		}
		a[i - 1] = (int)par->nb;
		ft_lstadd_back_p(list_a, ft_lstnew_p((int)par->nb));
		if (!check_double(i, a))
		{
			free(a);
			return (0);
		}
		par->len++;
		i++;
	}
	return (1);
}

int	check_top_bottom(t_p_list **lst, t_var *par)
{
	int			count;
	int			i;
	t_p_list	*tmp;

	count = 0;
	i = 0;
	tmp = (*lst);
	while (tmp != NULL)
	{
		if (tmp->order == par->next)
			count = i;
		i++;
		tmp = tmp->next;
	}
	return (count);
}
