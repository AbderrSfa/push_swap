# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 11:04:13 by asfaihi           #+#    #+#              #
#    Updated: 2021/07/16 10:46:36 by asfaihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_NAME = push_swap

CHECKER_NAME = checker

PUSH_SWAP_SRC = push_swap.c check_errors.c fill_stacks.c libft_functions.c libft_functions_2.c \
		libft_functions_3.c pa_pb.c push_swap_tools.c ra_rb_rr.c rra_rrb_rrr.c \
		sa_sb_ss.c sort_array.c sort_five_hundred.c sort_one_hundred.c sort_ten.c \
		sort_three_and_five.c

CHECKER_SRC = checker.c execute_instructions.c get_next_line.c libft_functions.c \
		libft_functions_2.c libft_functions_3.c sa_sb_ss.c pa_pb.c ra_rb_rr.c \
		rra_rrb_rrr.c fill_stacks.c check_errors.c

FLAGS = -Wall -Wextra -Werror

PUSH_SWAP_OBJECT = $(PUSH_SWAP_SRC:.c=.o)

CHECKER_OBJECT = $(CHECKER_SRC:.c=.o)


all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJECT)
	gcc $(FLAGS) $(PUSH_SWAP_OBJECT) -o $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJECT)
	gcc $(FLAGS) $(CHECKER_OBJECT) -o $(CHECKER_NAME)

%.o:%.c
	gcc -c $<

clean:
	/bin/rm -f $(PUSH_SWAP_OBJECT)
	/bin/rm -f $(CHECKER_OBJECT)

fclean: clean
	/bin/rm -f $(PUSH_SWAP_NAME)
	/bin/rm -f $(CHECKER_NAME)

re: fclean all