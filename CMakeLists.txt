cmake_minimum_required(VERSION 3.19)
project(push_swap_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap_2 main.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_putstr_fd.c operation_a.c operation_b.c operation_both.c libft/ft_split.c libft/ft_substr.c ft_sort.c read_arg.c check_arg.c libft_lst.c throw_nb_stack.c
        check_arg_2.c check_b.c push_swap.c)