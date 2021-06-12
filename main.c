#include <stdio.h>
#include "push_swap.h"

p_list	*ft_lstnew_p(int content)
{
	p_list	*new_el;

	new_el = (p_list *)malloc(sizeof(p_list));
	if (!new_el)
		return (NULL);
	new_el->value = content;
	new_el->order = 0;
	new_el->flag = 0;
	new_el->next = NULL;
	return (new_el);
}

void	ft_lstadd_front_p(p_list **lst, p_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

p_list	*ft_lstlast_p(p_list *lst)
{
	p_list	*copy_lst;

	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst->next != NULL)
	{
		copy_lst = copy_lst->next;
	}
	return (copy_lst);
}

int	ft_lstsize_p(p_list *lst)
{
	int		count;
	p_list	*copy_lst;

	count = 0;
	copy_lst = lst;
	if (!lst)
		return (0);
	while (copy_lst != NULL)
	{
		count++;
		copy_lst = copy_lst->next;
	}
	return (count);
}

void	ft_lstadd_back_p(p_list **lst, p_list *new)
{
	p_list	*last_el;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last_el = ft_lstlast_p(*lst);
		last_el->next = new;
	}
}

long	ft_atoi_long(char *str)
{
	unsigned int	i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((sign == -1) && (res > 9223372036854775808u))
		return (0);
	if ((sign == 1) && (res >= 9223372036854775808u))
		return (-1);
	return (sign * res);
}

static void ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	quick_sort(int *sort, int l, int len_n)
{
	int right;
	int pivot;
	int left;

	left = l;
	right = len_n;
	pivot = sort[(left + right) / 2];
	while (left <= right)
	{
		while (sort[left] < pivot)
			left++;
		while (sort[right] > pivot)
			right--;
		if (left <= right)
			ft_swap(&sort[left++], &sort[right--]);
	}
	if (l < right) // сортируем левую часть
		quick_sort(sort, l, right);
	if (len_n > left) // сортируем правую часть
		quick_sort(sort, left, len_n);
}

static int *ft_sorted(int *sort, int *a, int len)
{
	int i;

	sort = ft_calloc((len + 1), sizeof(int));
	i = 0;
	while (i < len)
	{
		sort[i] = a[i];
		i++;
	}
	quick_sort(sort, 0, len - 1);
	return (sort);
}

static int read_argv(char **argv, int i, int *a, p_list **lst)
{
	int j;
	long nb;

	j = 0;
	nb = 0;
	while (argv[i][j])
	{
		if ((!ft_isdigit(argv[i][j])) && (argv[i][j] != '-')) // проверка что// не// буквы
		{
			ft_putstr_fd("Error0", 1);
			return (0);
		}
		nb = ft_atoi_long(argv[i]); // выделяем из строки число
		//nb = nb * 10 + argv[i][j] - '0'; // выделяем из строки число
		if ((nb > 2147483647) || (nb < -2147483648)) //проверка на int
		{
			ft_putstr_fd("Error1", 1);
			return (0);
		}
		j++;
	}
	//ft_lstnew((int)nb);
	a[i - 1] = (int)nb;
	//printf("nb = %d\n", (int)nb);
	//ft_lstnew_p((int)nb);
	ft_lstadd_back_p(lst, ft_lstnew_p((int)nb));
	//printf("cont = %d\n", *par->value);
	//par->content = (int)nb; // кладем в структуру число
	//par->
	//par->len++;
	return (1);
}

static int check_double(int i, int *a)
{
	int k;

	k = 0;
	while (k < i - 1) //проверка на дубликаты
	{
		if (a[k] == a[i - 1])
		{
			ft_putstr_fd("Error2", 1);
			return (0);
		}
		k++;
	}
	return (1);
}


void print_list(p_list **lst1, p_list **lst2)
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

static int if_sort(int *a, int i, int len)
{
	while (a[i] < a[i + 1] && i < len - 1)
		i++;
	if (i != len - 1)
		return (0);
	else
		return (1);
}

void ft_order(p_list **head_a, int *sort)
{
	p_list *tmp;
	int i;

	tmp = (*head_a);
	while (tmp != NULL)
	{
		i = 0;
		while (sort[i] != tmp->value)
			i++;
		tmp->order = i + 1;
		tmp = tmp->next;
	}
}

void from_A_to_B(p_list **head_a, p_list **head_b, t_var *par)
{
	int i;

	i = 0;
	while (i < par->mid)
	{
		if ((*head_a)->order <= par->mid)
		{
			(*head_a)->flag++;
			ft_pb(head_a, head_b);
			i++;
		}
		else
			ft_ra(head_a);
	}
}

void from_B_to_A(p_list **head_a, p_list **head_b, t_var *par)
{
	int i;

	i = 0;
	while (i < par->size_b / 2 + 1)
	{
		if ((*head_b)->order >= par->mid)
		{
			ft_pa(head_a, head_b);
			i++;
		}
		else
			ft_rb(head_b);
	}
}

int if_sort_list(p_list **head_a)
{
	p_list *tmp;
	p_list *tmp2;

	tmp = (*head_a);
	tmp2 = (*head_a)->next;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp2->value)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		else
			return (0);
	}
	return (1);
}

int ft_find_order(p_list **head_a, t_var *par)
{
	p_list *tmp;

	tmp = (*head_a)->next;
	par->c = (*head_a)->order;
	while (tmp != NULL)
	{
		if (tmp->order > par->c)
			par->c = tmp->order;
		tmp = tmp->next;
	}
	return (par->c);
}

int main(int argc, char **argv)
{
	int i;
	int *a;
	int *sort;
	p_list *list_a;
	p_list *list_b;
	t_var par;

//	list_a = (p_list *)malloc(sizeof(p_list));
//	list_b = (p_list *)malloc(sizeof(p_list));
	list_a = NULL;
	list_b = NULL;
	//par = NULL;
	par.len = 0;
	par.next = 1;
	par.flag = 0;
	if (argc > 1)
	{
		i = 1;
		a = ft_calloc((2 * argc), (sizeof(int)));
		sort = ft_calloc((2 * argc), (sizeof(int)));
		while (i < argc)
		{
			if (!read_argv(argv, i, a, &list_a) || !check_double(i, a))
			{
				free(a);
				return (0);
			}
			par.len++;
			i++;
		}
		printf("%d\n", par.len);
		if (if_sort(a, 0, par.len))
		{
			free(a);
			return (0);
		}
		sort = ft_sorted(sort, a, par.len);
		//printf("cont = %d\n", list_a->value);
		printf("\nsort: ");
		for (int k = 0; k < par.len; k++)
			printf("%d ", sort[k]);
		printf("\n");
//		ft_pb(&list_a, &list_b);
//		ft_pb(&list_a, &list_b);
//		ft_pb(&list_a, &list_b);
//		ft_rra(&list_a);
//		print_list(&list_a);

		ft_order(&list_a, sort);
		//print_list(&list_a);
		par.max = par.len;
		par.mid = par.max / 2 + par.next;
		printf("mid = %d\n", par.mid);

		//int size_b;
		from_A_to_B(&list_a, &list_b, &par);
		print_list(&list_a, &list_b);
		while (!(if_sort_list(&list_a) && list_b == NULL))
		{
			//from_A_to_B(&list_a, &list_b, &par);
			print_list(&list_a, &list_b);
			par.flag++;

			par.size_b = ft_lstsize_p(list_b);
			while (par.size_b > 3)
			{
				par.max = ft_find_order(&list_b, &par);
				//par.max = par.mid;
				par.mid = (par.max - par.next) / 2 + par.next;
				//par.mid = ft_find_order(&list_a, &par);
				from_B_to_A(&list_a, &list_b, &par);
				par.size_b = ft_lstsize_p(list_b);
			}

			if (par.size_b == 3)
			{
				while (list_b->order != par.next)
					ft_ra(&list_b);
				if (list_b->order == par.next)
				{
					ft_pa(&list_a, &list_b);
					ft_ra(&list_a);
					par.next++;
//					par.max++;
//					par.mid++;
					par.size_b--;
				}
			}
			if (par.size_b == 2)
			{
				if ((list_b)->value < list_b->next->value)
					ft_sb(&list_b);
				ft_pa(&list_a, &list_b);
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				ft_ra(&list_a);
				par.next += 2;
//				par.mid += 2;
//				par.max += 2;
			}
			else if (par.size_b == 1)
			{
				ft_pa(&list_a, &list_b);
				ft_ra(&list_a);
				par.next++;
//				par.mid++;
//				par.max++;
			}
			while (list_a->order == par.next)
			{
				ft_ra(&list_a);
				par.next++;
//				par.mid++;
			}
			print_list(&list_a, &list_b);

			if (if_sort_list(&list_a))
				return (1);
			par.c = 0;
			while (par.flag >= 0)
			{
				while ((list_a->flag == par.flag) && list_a->order != 1)
				{
					ft_pb(&list_a, &list_b);
					par.c = 1;
					list_b->flag++;
				}
				if (par.c == 1)
					break;
				par.flag--;
			}
//			if ((list_a->flag == par.flag) && list_a->order != 1)
//			{
//				while ((list_a->flag == par.flag) && list_a->order != 1)
//				{
//					ft_pb(&list_a, &list_b);
//					par.c++;
//					list_b->flag++;
//				}
//				//par.flag--;
//			}
//			else
//			{
//				while (par.flag >= 0)
//				{
//					par.flag--;
//					while ((list_a->flag == par.flag) && list_a->order != 1)
//					{
//						ft_pb(&list_a, &list_b);
//						par.c++;
//						list_b->flag++;
//					}
//				}
//			}
//			else if (--par.flag == list_a->flag && list_a->order != 1)
//			{
//				//par.flag--;
//				while (par.flag == list_a->flag)
//				{
//					ft_pb(&list_a, &list_b);
//					list_b->flag++;
//					par.c++;
//				}
//			}
//			else if (list_a->flag == 0 && list_a->order != 1)
		}
		print_list(&list_a, &list_b);
	}
}
