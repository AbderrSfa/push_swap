# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 11:04:13 by asfaihi           #+#    #+#              #
#    Updated: 2021/07/15 13:13:34 by asfaihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c check_errors.c fill_stacks.c libft_functions.c libft_functions_2.c \
		libft_functions_3.c pa_pb.c push_swap_tools.c ra_rb_rr.c rra_rrb_rrr.c \
		sa_sb_ss.c sort_array.c sort_five_hundred.c sort_one_hundred.c sort_ten.c \
		sort_three_and_five.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	gcc $(OBJECT) -o $(NAME)

%.o:%.c
	gcc -c $<

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all