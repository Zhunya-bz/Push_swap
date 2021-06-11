#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

typedef struct s_push_list
{
	int 				value;
	int					flag;
	struct s_push_list	*next;
}			p_list;

void ft_pb(p_list **head_a, p_list **head_b);
void ft_pa(p_list **head_a, p_list **head_b);
void ft_sa(p_list **head_a);
void ft_sb(p_list **head_b);
void ft_ra(p_list **head_a);
void ft_rb(p_list **head_b);
void ft_rr(p_list **head_a, p_list **head_b);
void ft_rra(p_list **head_a);
void ft_rrb(p_list **head_b);
void ft_rrr(p_list **head_a, p_list **head_b);


#endif

