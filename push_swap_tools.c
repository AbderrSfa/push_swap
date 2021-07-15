/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:57:22 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 11:00:06 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number_within_chunk(t_stacks *stacks, int chunk_endpoint)
{
	int		i;

	i = 0;
	while (i < stacks->stack_a.in_use)
	{
		if (stacks->stack_a.array[i] <= chunk_endpoint)
			return (i);
		i++;
	}
	return (-1);
}

void	move_to_top(t_stacks *stacks, int index)
{
	int		midway;

	midway = stacks->stack_a.in_use / 2;
	while (index != 0)
	{
		if (index <= midway)
		{
			ft_ra(stacks, PRINT);
			index--;
		}
		else
		{
			ft_rra(stacks, PRINT);
			index++;
			if (index == stacks->stack_a.in_use)
				break ;
		}
	}
}

void	move_to_b(t_stacks *stacks, int chunk_endpoint)
{
	int		index;

	index = get_number_within_chunk(stacks, chunk_endpoint);
	while (index != -1)
	{
		move_to_top(stacks, index);
		ft_pb(stacks);
		index = get_number_within_chunk(stacks, chunk_endpoint);
	}
}

int	get_chunk_endpoint(int *sorted_arr, int size, int part, int chunk)
{
	int		chunk_endpoint;

	chunk_endpoint = sorted_arr[(size * part) / chunk];
	return (chunk_endpoint);
}
