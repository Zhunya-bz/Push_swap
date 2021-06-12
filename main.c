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

int main(int argc, char **argv)
{
	int *a;
	int *sort;
	p_list *list_a;
	p_list *list_b;
	t_var par;

	list_a = NULL;
	list_b = NULL;
	par.len = 0;
	par.next = 1;
	par.flag = 0;
	par.argc = argc;
	if (argc > 1)
	{
		a = ft_calloc((2 * argc), (sizeof(int)));
		sort = ft_calloc((2 * argc), (sizeof(int)));
		if (argc == 2)
		{
			if (!check_string(argv, &par, &list_a, a))
				return (0);
		}
		else
			if (!check_argument(argv, &par, &list_a, a))
				return (0);
		if (if_sort(a, 0, par.len))
		{
			free(a);
			return (0);
		}
		sort = ft_sorted(sort, a, par.len);
		ft_order(&list_a, sort);
		free(a);
		par.max = par.len;
		par.mid = par.max / 2 + par.next;
		from_A_to_B(&list_a, &list_b, &par);
		par.flag++;
		par.size_b = ft_lstsize_p(list_b);
		int c;
		c = 1;
		while (par.size_b > 3)
		{
			par.max = ft_find_order(&list_b, &par);
			par.mid = (par.max - par.next) / 2 + par.next;
			from_B_to_A(&list_a, &list_b, &par, c);
			par.size_b = ft_lstsize_p(list_b);
			c++;
		}
		par.flag = c;
		if (par.size_b == 3)
		{
			while (list_b->order != par.next)
				ft_rb(&list_b);
			if (list_b->order == par.next)
			{
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				par.next++;
				par.size_b--;
			}
		}
		if (par.size_b == 2)
		{
			if (list_b->order == par.next)
			{
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				par.next++;
				par.size_b--;
			}
			else if (list_b->next->order == par.next)
			{
				ft_sb(&list_b);
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				par.next++;
				par.size_b--;
			}
			else
			{
				ft_pa(&list_a, &list_b);
				ft_pa(&list_a, &list_b);
				par.size_b -= 2;
			}
		}
		if (par.size_b == 1)
		{
			if (list_b->order == par.next)
			{
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				par.next++;
			}
			else
				ft_pa(&list_a, &list_b);
		}
		if (list_a->next->order == par.next)
		{
			ft_sa(&list_a);
			ft_ra(&list_a);
			par.next++;
		}
		while (list_a->order == par.next)
		{
			ft_ra(&list_a);
			par.next++;
		}
		if (if_sort_list(&list_a))
			return (0);
		par.c = 0;
		while (par.flag >= 0)
		{
			while ((list_a->flag == par.flag) && list_a->order != 1)
			{
				ft_pb(&list_a, &list_b);
				par.c = 1;
			}
			if (par.c == 1)
				break;
			par.flag--;
		}
		int k = 0;
		int i = 0;
		while (!(if_sort_list(&list_a) && list_b == NULL))
		{
			par.size_b = ft_lstsize_p(list_b);
				if (par.flag == 0)
				{
					c = 1;
					par.size_b = ft_lstsize_p(list_b);
					while (par.size_b > 3 && list_b != NULL)
					{
						par.max = ft_find_order(&list_b, &par);
						par.mid = (par.max - par.next) / 2 + par.next;
						from_B_to_A(&list_a, &list_b, &par, c);
						par.size_b = ft_lstsize_p(list_b);
						c++;
					}
					par.flag = c;
					if (par.size_b == 3)
					{
						while (list_b->order != par.next)
							ft_rb(&list_b);
						if (list_b->order == par.next)
						{
							ft_pa(&list_a, &list_b);
							ft_ra(&list_a);
							par.next++;
							par.size_b--;
						}
					}
					if (par.size_b == 2)
					{
						if (list_b->order == par.next)
						{
							ft_pa(&list_a, &list_b);
							ft_ra(&list_a);
							par.next++;
							par.size_b--;
						} else if (list_b->next->order == par.next)
						{
							ft_sb(&list_b);
							ft_pa(&list_a, &list_b);
							ft_ra(&list_a);
							par.next++;
							par.size_b--;
						} else
						{
							ft_pa(&list_a, &list_b);
							ft_pa(&list_a, &list_b);
							par.size_b -= 2;
						}
					}
					if (par.size_b == 1)
					{
						if (list_b->order == par.next)
						{
							ft_pa(&list_a, &list_b);
							ft_ra(&list_a);
							par.next++;
						}
						else
							ft_pa(&list_a, &list_b);
					}
					if (list_a->next->order == par.next)
					{
						ft_sa(&list_a);
						ft_ra(&list_a);
						par.next++;
					}
					while (list_a->order == par.next)
					{
						ft_ra(&list_a);
						par.next++;
					}
					if (if_sort_list(&list_a))
						return (0);
					par.c = 0;
					while (par.flag >= 0)
					{
						while ((list_a->flag == par.flag) && list_a->order != 1)
						{
							ft_pb(&list_a, &list_b);
							par.c = 1;
						}
						if (par.c == 1)
							break;
						par.flag--;
					}
				}
			par.size_b = ft_lstsize_p(list_b);
			while (par.size_b > 3)
			{
				i = 0;
				k = check_top_bottom(&list_b, &par);
				if (k <= par.size_b / 2)
				{
					while (i < k)
					{
						ft_rb(&list_b);
						i++;
					}
				}
				else
				{
					while (i < par.size_b - k)
					{
						ft_rrb(&list_b);
						i++;
					}
				}
				if (list_b->order == par.next)
				{
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
					par.size_b--;
				}
			}
			if (list_a->next->order == par.next)
			{
				ft_sa(&list_a);
				ft_ra(&list_a);
				par.next++;
			}
			while (list_a->order == par.next)
			{
				ft_ra(&list_a);
				par.next++;
			}
			if (par.size_b == 3)
			{
				while (list_b->order != par.next)
					ft_rb(&list_b);
				if (list_b->order == par.next)
				{
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
					par.size_b--;
				}
			}
			if (par.size_b == 2)
			{
				if (list_b->order == par.next)
				{
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
					par.size_b--;
				}
				else if (list_b->next->order == par.next)
				{
					ft_sb(&list_b);
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
					par.size_b--;
				}
				else
				{
					ft_pa(&list_a, &list_b);
					ft_pa(&list_a, &list_b);
					par.size_b -= 2;
				}
			}
			if (par.size_b == 1)
			{
				if (list_b->order == par.next)
				{
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
				}
				else
					ft_pa(&list_a, &list_b);
			}
			if (list_a->next->order == par.next)
			{
				ft_sa(&list_a);
				ft_ra(&list_a);
				par.next++;
			}
			while (list_a->order == par.next)
			{
				ft_ra(&list_a);
				par.next++;
			}
			if (if_sort_list(&list_a))
			{
				return (0);
			}
			par.c = 0;
			while (par.flag >= 0)
			{
				while ((list_a->flag == par.flag) && list_a->order != 1)
				{
					ft_pb(&list_a, &list_b);
					par.c = 1;
				}
				if (par.c == 1)
					break;
				par.flag--;
			}
		}
	}
}
