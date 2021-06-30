#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

typedef struct s_push_list
{
	int 				value;
	int					flag;
	int 				order;
	struct s_push_list	*next;
}			p_list;

typedef struct s_variable
{
	int len;
	int mid;
	int flag;
	int max;
	int next;
	int c;
	int size_b;
	int size_a;
	long nb;
	int argc;
}				t_var;

void	ft_pb(p_list **head_a, p_list **head_b, int flag);
void	ft_pa(p_list **head_a, p_list **head_b, int flag);
void	ft_sa(p_list **head_a, int flag);
void	ft_sb(p_list **head_b, int flag);
void	ft_ss(p_list **head_a, p_list **head_b, int flag);
void	ft_ra(p_list **head_a, int flag);
void	ft_rb(p_list **head_b, int flag);
void	ft_rr(p_list **head_a, p_list **head_b, int flag);
void	ft_rra(p_list **head_a, int flag);
void	ft_rrb(p_list **head_b, int flag);
void	ft_rrr(p_list **head_a, p_list **head_b, int flag);
void	ft_lstadd_back_p(p_list **lst, p_list *new);
p_list	*ft_lstlast_p(p_list *lst);
int		ft_lstsize_p(p_list *lst);
p_list	*ft_lstnew_p(int content);
void	clear_list(p_list **lst);
int		argument(int argc, char **argv, t_var *par, p_list **list_a);
int		check_sort(int *a, t_var *par, p_list **list_a);
int		check_2_nb(t_var *par, p_list **list_a);
void	check_size_b_3(t_var *par, p_list **list_a, p_list **list_b);
void	check_size_b_2(t_var *par, p_list **list_a, p_list **list_b);
void	check_first_2_A(t_var *par, p_list **list_a);
void	check_size_b_1(t_var *par, p_list **list_a, p_list **list_b);
void	check_flags_stack(t_var *par, p_list **list_a, p_list **list_b);
int		general_cycle(t_var *par, p_list **list_a, p_list **list_b);
void	ft_check_top_bottom(t_var *par, p_list **list_a, p_list **list_b);
void	throw_stack_B(t_var *par, p_list **list_a, p_list **list_b);
void	first_step(t_var *par, p_list **list_a, p_list **list_b);
void	fill_param(t_var *par, p_list **list_a, p_list **list_b, int argc);
int		if_sort(int *a, int i, int len);
int		*ft_sorted(int *sort, int *a, int len);
int		if_sort_list(p_list **head_a);
int		check_top_bottom(p_list **lst, t_var *par);
int		read_argv(char **argv, int i, t_var *par);
int		check_argument(char **argv, t_var *par, p_list **list_a, int *a);
int		check_string(char **argv, t_var *par, p_list **list_a, int *a);
int		ft_find_order(p_list **head_a, t_var *par);
void	from_A_to_B(p_list **head_a, p_list **head_b, t_var *par);
void	from_B_to_A(p_list **head_a, p_list **head_b, t_var *par, int c);
void	ft_order(p_list **head_a, int *sort);

#endif

