/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:09:43 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 15:33:28 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define PRINT 1
# define NO_PRINT 0

typedef struct s_array		t_array;
struct						s_array
{
	int						*array;
	int						size;
	int						in_use;
};

typedef struct s_stacks		t_stacks;
struct						s_stacks
{
	t_array					stack_a;
	t_array					stack_b;
};

// Libft functions:
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
long		ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char v);

//push_swap instructions:
void		ft_sa(t_stacks *stacks, int print);
void		ft_sb(t_stacks *stacks, int print);
void		ft_ss(t_stacks *stacks);
void		ft_pa(t_stacks *stacks);
void		ft_pb(t_stacks *stacks);
void		ft_ra(t_stacks *stacks, int print);
void		ft_rb(t_stacks *stacks, int print);
void		ft_rr(t_stacks *stacks);
void		ft_rra(t_stacks *stacks, int print);
void		ft_rrb(t_stacks *stacks, int print);
void		ft_rrr(t_stacks *stacks);

// push_swap functions:
int			end_program(int ret, char *message, t_stacks *stacks);
int			are_args_valid(char **argv);
int			duplicate_arg(t_stacks *stacks, int num);
int			stack_is_sorted(t_stacks *stacks);
void		init_stacks(int argc, t_stacks *stacks);
t_stacks	ft_fill_stacks(int argc, char **argv);
void		push_stack_down(int *array, int in_use);
void		pop_stack_up(int *array, int in_use);
int			get_smallest_index(t_stacks *stacks);
void		get_smallest_to_top_five(t_stacks *stacks);
void		get_smallest_to_top_ten(t_stacks *stacks);
void		swap_values(int *a, int *b);
int			*init_array(t_stacks *stacks);
int			*sort_array(t_stacks *stacks);
void		get_biggest_to_top(t_stacks *stacks);

void		sort_three_numbers(t_stacks *stacks);
void		sort_four_or_five(t_stacks *stacks);
void		sort_six_to_ten(t_stacks *stacks);
void		sort_one_hundred(t_stacks *stacks);

#endif