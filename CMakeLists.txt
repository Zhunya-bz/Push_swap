cmake_minimum_required(VERSION 3.19)
project(push_swap_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap_2 main.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_putstr_fd.c operation_a.c operation_b.c operation_both.c)