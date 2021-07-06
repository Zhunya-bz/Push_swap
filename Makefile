SRCS = operation_a.c operation_b.c operation_both.c \
		libft_lst.c read_arg.c \
		check_arg.c check_arg_2.c check_b.c \
		throw_nb_stack.c ft_sort.c \
		less_5_param.c \
		main.c \
		push_swap.c \

SRCS_CHECK = get_next_line.c \
			checker.c \
			operation_a.c operation_b.c operation_both.c \
			libft_lst.c read_arg.c \
			check_arg.c check_arg_2.c check_b.c \
			throw_nb_stack.c ft_sort.c \
			push_swap.c

OBJS_CHECK = ${SRCS_CHECK:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = push_swap

NAME_CHECK = checker

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./push_swap.h libft/libft.h

LIB_DIR = ./libft

${NAME}:	${OBJS} ${HEADER}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} libft/libft.a ${OBJS} -o ${NAME}

all:    ${NAME}

clean:      
		${RM} ${OBJS} ${OBJS_CHECK}
		make clean -C ${LIB_DIR}

fclean: clean
		${RM} ${NAME} ${NAME_CHECK} ${OBJS_CHECK}
		make fclean -C ${LIB_DIR}

re:     fclean all

bonus:  ${OBJS_CHECK} ${HEADER}
		${CC} ${CFLAGS} libft/libft.a ${OBJS_CHECK} -o ${NAME_CHECK}

.PHONY: fclean clean all re