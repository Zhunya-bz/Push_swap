#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_push_list
{
	int					value;
	int					flag;
	int					order;
	struct s_push_list	*next;
}			t_p_list;

typedef struct s_variable
{
	int		len;
	int		mid;
	int		flag;
	int		max;
	int		next;
	int		c;
	int		size_b;
	int		size_a;
	long	nb;
	int		argc;
	int		z;
}				t_var;

void		ft_pb(t_p_list **head_a, t_p_list **head_b, int flag);
void		ft_pa(t_p_list **head_a, t_p_list **head_b, int flag);
void		ft_sa(t_p_list **head_a, int flag);
void		ft_sb(t_p_list **head_b, int flag);
void		ft_ss(t_p_list **head_a, t_p_list **head_b, int flag);
void		ft_ra(t_p_list **head_a, int flag);
void		ft_rb(t_p_list **head_b, int flag);
void		ft_rr(t_p_list **head_a, t_p_list **head_b, int flag);
void		ft_rra(t_p_list **head_a, int flag);
void		ft_rrb(t_p_list **head_b, int flag);
void		ft_rrr(t_p_list **head_a, t_p_list **head_b, int flag);
void		ft_lstadd_back_p(t_p_list **lst, t_p_list *new);
t_p_list	*ft_lstlast_p(t_p_list *lst);
int			ft_lstsize_p(t_p_list *lst);
t_p_list	*ft_lstnew_p(int content);
void		clear_list(t_p_list **lst);
int			get_next_line(int fd, char **line);
int			argument(int argc, char **argv, t_var *par, t_p_list **list_a);
void		few_par(int argc, t_var *par, t_p_list **list_a, t_p_list **list_b);
int			check_sort(int *a, t_var *par, t_p_list **list_a);
int			check_2_nb(t_var *par, t_p_list **list_a);
void		check_size_b_3(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		check_size_b_2(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		check_first_2_A(t_var *par, t_p_list **list_a);
void		check_size_b_1(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		check_flags_stack(t_var *par, t_p_list **list_a, t_p_list **list_b);
int			general_cycle(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		ft_check_top_bot(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		throw_stack_B(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		first_step(t_var *par, t_p_list **list_a, t_p_list **list_b);
void		fill_p(t_var *par, t_p_list **list_a, t_p_list **list_b, int argc);
int			if_sort(int *a, int i, int len);
int			*ft_sorted(int *sort, int *a, int len);
int			if_sort_list(t_p_list **head_a);
int			check_top_bottom(t_p_list **lst, t_var *par);
int			read_argv(char **argv, int i, t_var *par);
int			check_argument(char **argv, t_var *par, t_p_list **list_a, int *a);
int			argum_checker(int argc, char **argv, t_var *par, t_p_list **list_a);
int			check_string(char **argv, t_var *par, t_p_list **list_a, int *a);
int			ft_find_order(t_p_list **head_a, t_var *par);
void		from_A_to_B(t_p_list **head_a, t_p_list **head_b, t_var *par);
void		from_B_to_A(t_p_list **h_a, t_p_list **h_b, t_var *par, int c);
void		ft_order(t_p_list **head_a, int *sort);

#endif
