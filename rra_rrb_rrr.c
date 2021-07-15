/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:37:34 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:38:18 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stacks, int print)
{
	int		temp;

	if (print == PRINT)
		ft_putendl_fd("rra", 1);
	temp = stacks->stack_a.array[stacks->stack_a.in_use - 1];
	push_stack_down(stacks->stack_a.array, stacks->stack_a.in_use);
	stacks->stack_a.array[0] = temp;
}

void	ft_rrb(t_stacks *stacks, int print)
{
	int		temp;

	if (print == PRINT)
		ft_putendl_fd("rrb", 1);
	temp = stacks->stack_b.array[stacks->stack_b.in_use - 1];
	push_stack_down(stacks->stack_b.array, stacks->stack_b.in_use);
	stacks->stack_b.array[0] = temp;
}

void	ft_rrr(t_stacks *stacks)
{
	ft_putendl_fd("rrr", 1);
	ft_rra(stacks, NO_PRINT);
	ft_rra(stacks, NO_PRINT);
}
