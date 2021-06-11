#include <stdio.h>
#include "push_swap.h"

p_list	*ft_lstnew_p(int content)
{
	p_list	*new_el;

	new_el = (p_list *)malloc(sizeof(p_list));
	if (!new_el)
		return (NULL);
	new_el->value = content;
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

static int read_argv(char **argv, int i, int *a, p_list **par)
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
	ft_lstadd_back_p(par, ft_lstnew_p((int)nb));
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

void ft_pb(p_list **head_a, p_list **head_b)
{
	p_list *tmp;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	ft_putstr_fd("pb\n", 1);
	//printf("head_a1.value = %d\n", (*head_a)->value);
}

void ft_pa(p_list **head_a, p_list **head_b)
{
	p_list *tmp;

	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	ft_putstr_fd("pa\n", 1);
}

int main(int argc, char **argv)
{
	int i;
	int *a;
	p_list *list_a;
	p_list *list_b;

//	list_a = (p_list *)malloc(sizeof(p_list));
//	list_b = (p_list *)malloc(sizeof(p_list));
	list_a = NULL;
	list_b = NULL;
	if (argc > 1)
	{
		i = 1;
		a = ft_calloc((2 * argc), (sizeof(int)));
		while (i < argc)
		{
			if (!read_argv(argv, i, a, &list_a))
			{
				free(a);
				return (0);
			}
			if (!check_double(i, a))
			{
				free(a);
				return (0);
			}
			i++;
		}
		printf("cont = %d\n", list_a->value);
		ft_pb(&list_a, &list_b);
		//ft_pb(&list_a, &list_b);
		ft_pa(&list_a, &list_b);
		printf("list_b.value = %d\n", list_b->value);
//		printf("list_a.value = %d\n", list_a->value);
	}
}
