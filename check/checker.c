#include "../push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	p_list	*list_a;
	p_list	*list_b;
	t_var	par;
	char	*str;

	fill_param(&par, &list_a, &list_b, argc);
	if (argc > 1)
	{
		if (argument(argc, argv, &par, &list_a))
		{
			while(get_next_line(0, &str))
			{
				if (!ft_strncmp(str, "pb", 2))
					ft_pb(&list_a, &list_b, 0);
				if (!ft_strncmp(str, "pa", 2))
					ft_pa(&list_a, &list_b, 0);
				if (!ft_strncmp(str, "sa", 2))
					ft_sa(&list_a, 0);
				if (!ft_strncmp(str, "sb", 2))
					ft_sb(&list_b, 0);
				if (!ft_strncmp(str, "ra", 2))
					ft_ra(&list_a, 0);
				if (!ft_strncmp(str, "rra", 3))
					ft_rra(&list_a, 0);
				if (!ft_strncmp(str, "rb", 2))
					ft_rb(&list_b, 0);
				if (!ft_strncmp(str, "rrb", 3))
					ft_rrb(&list_b, 0);
				if (!ft_strncmp(str, "ss", 2))
					ft_ss(&list_a, &list_b, 0);
				if (!ft_strncmp(str, "rr", 2))
					ft_rr(&list_a, &list_b, 0);
				if (!ft_strncmp(str, "rrr", 3))
					ft_rrr(&list_a, &list_b, 0);

				//printf("%s", str);
			}
			if (list_b == NULL && if_sort_list(&list_a))
				printf("OK\n");
			else
				printf("KO\n");

//			first_throw(&par, &list_a, &list_b);
//			if (if_sort_list(&list_a))
//				break ;
//			check_flags_stack(&par, &list_a, &list_b);
//			if (!general_cycle(&par, &list_a, &list_b))
//				break ;
//			clear_list(&list_a);
//			break ;
		}
	}
}