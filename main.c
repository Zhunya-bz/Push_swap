#include "push_swap.h"

static void	first_throw( t_var *par, p_list **list_a, p_list **list_b)
{
	first_step(par, list_a, list_b);
	throw_stack_B(par, list_a, list_b);
	check_size_b_3(par, list_a, list_b);
	check_size_b_2(par, list_a, list_b);
	check_size_b_1(par, list_a, list_b);
}

int	main(int argc, char **argv)
{
	p_list	*list_a;
	p_list	*list_b;
	t_var	par;

	fill_param(&par, &list_a, &list_b, argc);
	if (argc > 1)
	{
		while (argument(argc, argv, &par, &list_a) && check_2_nb(&par, &list_a))
		{
			first_throw(&par, &list_a, &list_b);
			if (if_sort_list(&list_a))
				break ;
			check_flags_stack(&par, &list_a, &list_b);
			if (!general_cycle(&par, &list_a, &list_b))
				break ;
			clear_list(&list_a);
			break ;
		}
	}
	return (0);
}
