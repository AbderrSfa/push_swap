/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:36:17 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:38:13 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_down(int *array, int in_use)
{
	while (in_use > 0)
	{
		array[in_use] = array[in_use - 1];
		in_use--;
	}
}

void	pop_stack_up(int *array, int in_use)
{
	int		i;

	i = 0;
	while (i < in_use)
	{
		array[i] = array[i + 1];
		i++;
	}
}

void	ft_pb(t_stacks *stacks)
{
	int		i;

	i = 0;
	ft_putendl_fd("pb", 1);
	if (stacks->stack_a.in_use == 0)
		return ;
	if (stacks->stack_b.in_use == 0)
		stacks->stack_b.array[0] = stacks->stack_a.array[0];
	else
	{
		push_stack_down(stacks->stack_b.array, stacks->stack_b.in_use);
		stacks->stack_b.array[0] = stacks->stack_a.array[0];
	}
	pop_stack_up(stacks->stack_a.array, stacks->stack_a.in_use);
	stacks->stack_b.in_use++;
	stacks->stack_a.in_use--;
}

void	ft_pa(t_stacks *stacks)
{
	int		i;

	i = 0;
	ft_putendl_fd("pa", 1);
	if (stacks->stack_b.in_use == 0)
		return ;
	if (stacks->stack_a.in_use == 0)
		stacks->stack_a.array[0] = stacks->stack_b.array[0];
	else
	{
		push_stack_down(stacks->stack_a.array, stacks->stack_a.in_use);
		stacks->stack_a.array[0] = stacks->stack_b.array[0];
	}
	pop_stack_up(stacks->stack_b.array, stacks->stack_b.in_use);
	stacks->stack_a.in_use++;
	stacks->stack_b.in_use--;
}
