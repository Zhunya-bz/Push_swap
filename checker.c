#include "push_swap.h"
#include "get_next_line.h"

static int	fun_comp(t_p_list **list_a, t_p_list **list_b, char *str)
{
	if (!ft_strncmp(str, "pb", 2))
		ft_pb(list_a, list_b, 0);
	else if (!ft_strncmp(str, "pa", 2))
		ft_pa(list_a, list_b, 0);
	else if (!ft_strncmp(str, "sa", 2))
		ft_sa(list_a, 0);
	else if (!ft_strncmp(str, "sb", 2))
		ft_sb(list_b, 0);
	else if (!ft_strncmp(str, "ra", 2))
		ft_ra(list_a, 0);
	else if (!ft_strncmp(str, "rra", 3))
		ft_rra(list_a, 0);
	else if (!ft_strncmp(str, "rb", 2))
		ft_rb(list_b, 0);
	else if (!ft_strncmp(str, "rrb", 3))
		ft_rrb(list_b, 0);
	else if (!ft_strncmp(str, "ss", 2))
		ft_ss(list_a, list_b, 0);
	else if (!ft_strncmp(str, "rr", 2))
		ft_rr(list_a, list_b, 0);
	else if (!ft_strncmp(str, "rrr", 3))
		ft_rrr(list_a, list_b, 0);
	else
		return (0);
	return (1);
}

static int	main_cycle(t_p_list **list_a, t_p_list **list_b, char *str, int i)
{
	while (i)
	{
		if (!fun_comp(list_a, list_b, str))
		{
			if (ft_strncmp(str, "", 1))
			{
				ft_putstr_fd("Error\n", 1);
				free(str);
				return (0);
			}
		}
		free(str);
		i = get_next_line(0, &str);
	}
	return (1);
}

static int	fun_errors(char *str)
{
	if (!ft_strncmp(str, "", 1))
	{
		ft_putstr_fd("Error\n", 1);
		free(str);
		return (0);
	}
	return (1);
}

static void	general_f(t_p_list **list_a, t_p_list **list_b, char *str, int i)
{
	while (main_cycle(list_a, list_b, str, i))
	{
		if (i == 0)
		{
			if (!fun_comp(list_a, list_b, str))
				if (!fun_errors(str))
					break ;
		}
		if (*list_b == NULL && if_sort_list(list_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		break ;
	}
}

int	main(int argc, char **argv)
{
	t_p_list	*list_a;
	t_p_list	*list_b;
	t_var		par;
	char		*str;
	int			i;

	fill_p(&par, &list_a, &list_b, argc);
	if (argc > 1)
	{
		par.z = argum_checker(argc, argv, &par, &list_a);
		if (par.z == 1)
		{
			i = get_next_line(0, &str);
			if (!fun_errors(str))
				return (0);
			general_f(&list_a, &list_b, str, i);
		}
		else if (par.z == 2)
		{
			ft_putstr_fd("OK\n", 1);
		}
	}
	return (0);
}
