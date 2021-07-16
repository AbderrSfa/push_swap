/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:04:37 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/16 10:40:17 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_index(t_stacks *stacks)
{
	int		i;
	int		biggest_index;

	i = 0;
	biggest_index = i;
	while (i < stacks->stack_b.in_use)
	{
		if (stacks->stack_b.array[i] > stacks->stack_b.array[biggest_index])
			biggest_index = i;
		i++;
	}
	return (biggest_index);
}

void	get_biggest_to_top(t_stacks *stacks)
{
	int		biggest_index;

	biggest_index = get_biggest_index(stacks);
	while (biggest_index != 0)
	{
		if (biggest_index <= (stacks->stack_b.in_use / 2))
			ft_rb(stacks, PRINT);
		else
			ft_rrb(stacks, PRINT);
		biggest_index = get_biggest_index(stacks);
	}
}

void	sort_rest_of_numbers(t_stacks *stacks, int used_size)
{
	if (!stack_is_sorted(stacks))
	{
		while (stacks->stack_a.in_use >= 5)
		{
			get_smallest_to_top_ten(stacks);
			ft_pb(stacks, PRINT);
		}
		sort_four_or_five(stacks);
		while (stacks->stack_a.in_use != used_size)
			ft_pa(stacks, PRINT);
	}
}

void	sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.in_use == 2)
	{
		if (!stack_is_sorted(stacks))
			ft_sa(stacks, PRINT);
	}
	if (stacks->stack_a.in_use == 3)
		sort_three_numbers(stacks);
	if (stacks->stack_a.in_use == 4 || stacks->stack_a.in_use == 5)
		sort_four_or_five(stacks);
	if (stacks->stack_a.in_use > 5)
		sort_rest_of_numbers(stacks, stacks->stack_a.in_use);
}

void	sort_one_hundred(t_stacks *stacks)
{
	int		*sorted_array;
	int		chunk_endpoint;
	int		i;

	i = 1;
	sorted_array = sort_array(stacks);
	while (i != 4)
	{
		chunk_endpoint = get_chunk_endpoint(sorted_array,
				stacks->stack_a.size, i, 4);
		move_to_b(stacks, chunk_endpoint);
		i++;
	}
	free(sorted_array);
	sort_rest(stacks);
	while (stacks->stack_b.in_use != 0)
	{
		get_biggest_to_top(stacks);
		ft_pa(stacks, PRINT);
	}
}
