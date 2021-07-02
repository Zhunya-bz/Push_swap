#include "push_swap.h"

static void	first_throw( t_var *par, t_p_list **list_a, t_p_list **list_b)
{
	first_step(par, list_a, list_b);
	throw_stack_B(par, list_a, list_b);
	check_size_b_3(par, list_a, list_b);
	check_size_b_2(par, list_a, list_b);
	check_size_b_1(par, list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_p_list	*list_a;
	t_p_list	*list_b;
	t_var		par;

	fill_p(&par, &list_a, &list_b, argc);
	if (argc > 1)
	{
		while (argument(argc, argv, &par, &list_a) && check_2_nb(&par, &list_a))
		{
			if (argc <= 6)
			{
				few_par(argc, &par, &list_a, &list_b);
				break ;
			}
			else
			{
				first_throw(&par, &list_a, &list_b);
				if (if_sort_list(&list_a))
					break ;
				check_flags_stack(&par, &list_a, &list_b);
				if (!general_cycle(&par, &list_a, &list_b))
					break ;
				break ;
			}
		}
	}
	return (0);
}
