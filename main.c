#include "push_swap.h"
//#include <stdio.h>
//void	print_list(p_list **lst1, p_list **lst2)
//{
//	p_list	*tmp;
//
//	tmp = (*lst1);
//	printf("A:\n");
//	while (tmp != NULL)
//	{
//		printf("value = %d   ", tmp->value);
//		printf("order = %d   ", tmp->order);
//		printf("flag = %d\n", tmp->flag);
//		tmp = tmp->next;
//	}
//	tmp = (*lst2);
//	printf("B:\n");
//	while (tmp != NULL)
//	{
//		printf("value = %d   ", tmp->value);
//		printf("order = %d   ", tmp->order);
//		printf("flag = %d\n", tmp->flag);
//		tmp = tmp->next;
//	}
//}

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
				break;
			check_flags_stack(&par, &list_a, &list_b);
			if (!general_cycle(&par, &list_a, &list_b))
				break;
			break ;
		}
	}
	return (0);
}
