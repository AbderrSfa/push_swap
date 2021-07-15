/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:36:54 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:38:16 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stacks, int print)
{
	int		temp;

	if (print == PRINT)
		ft_putendl_fd("ra", 1);
	temp = stacks->stack_a.array[0];
	pop_stack_up(stacks->stack_a.array, stacks->stack_a.in_use);
	stacks->stack_a.array[stacks->stack_a.in_use - 1] = temp;
}

void	ft_rb(t_stacks *stacks, int print)
{
	int		temp;

	if (print == PRINT)
		ft_putendl_fd("rb", 1);
	temp = stacks->stack_b.array[0];
	pop_stack_up(stacks->stack_b.array, stacks->stack_b.in_use);
	stacks->stack_b.array[stacks->stack_b.in_use - 1] = temp;
}

void	ft_rr(t_stacks *stacks)
{
	ft_putendl_fd("rr", 1);
	ft_ra(stacks, NO_PRINT);
	ft_rb(stacks, NO_PRINT);
}
