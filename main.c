#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
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
