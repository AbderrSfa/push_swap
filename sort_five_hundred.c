/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderr_sfa <abderr_sfa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:59:34 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 22:50:59 by abderr_sfa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_than_hundred(t_stacks *stacks)
{
	if (stacks->stack_a.in_use == 2)
	{
		if (!stack_is_sorted(stacks))
			ft_sa(stacks, PRINT);
	}
	else if (stacks->stack_a.in_use == 3)
		sort_three_numbers(stacks);
	else if (stacks->stack_a.in_use == 4 || stacks->stack_a.in_use == 5)
		sort_four_or_five(stacks);
	else if (stacks->stack_a.in_use > 5 && stacks->stack_a.in_use <= 10)
		sort_rest_of_numbers(stacks, stacks->stack_a.in_use);
	else if (stacks->stack_a.in_use > 10)
		sort_one_hundred(stacks);
}

void	sort_five_hundred(t_stacks *stacks)
{
	int		*sorted_array;
	int		chunk_endpoint;
	int		i;

	i = 1;
	sorted_array = sort_array(stacks);
	while (i != 8)
	{
		chunk_endpoint = get_chunk_endpoint(sorted_array,
				stacks->stack_a.size, i, 8);
		move_to_b(stacks, chunk_endpoint);
		i++;
	}
	free(sorted_array);
	sort_more_than_hundred(stacks);
	while (stacks->stack_b.in_use != 0)
	{
		get_biggest_to_top(stacks);
		ft_pa(stacks, PRINT);
	}
}
