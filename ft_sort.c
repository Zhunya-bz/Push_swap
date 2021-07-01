#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	quick_sort(int *sort, int l, int len_n)
{
	int	right;
	int	pivot;
	int	left;

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
	if (l < right)
		quick_sort(sort, l, right);
	if (len_n > left)
		quick_sort(sort, left, len_n);
}

int	*ft_sorted(int *sort, int *a, int len)
{
	int	i;

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

int	if_sort(int *a, int i, int len)
{
	while (a[i] < a[i + 1] && i < len - 1)
		i++;
	if (i != len - 1)
		return (0);
	else
		return (1);
}
#include <stdio.h>
int	if_sort_list(p_list **head_a)
{
	p_list	*tmp;
	p_list	*tmp2;

	tmp = (*head_a);
	tmp2 = (*head_a)->next;
	while (tmp->next != NULL)
	{
//		printf("Cycle\n");
//		printf("%d %d\n", tmp->value, tmp2->value);
		if (tmp->value < tmp2->value)
		{
//			printf("%d %d\n", tmp->value, tmp2->value);
//			printf("da\n");
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		else
			return (0);
	}
	return (1);
}
