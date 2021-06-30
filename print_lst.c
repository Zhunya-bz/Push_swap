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