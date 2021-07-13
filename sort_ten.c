/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:38 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 12:00:07 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_smallest_to_top_ten(t_stacks *stacks)
{
	int		smallest_index;

	smallest_index = get_smallest_index(stacks);
	while (smallest_index != 0)
	{
		if (smallest_index > 5)
			ft_rra(stacks, PRINT);
		else
			ft_ra(stacks, PRINT);
		smallest_index = get_smallest_index(stacks);
	}
}

void	sort_six_to_ten(t_stacks *stacks)
{
	if (stack_is_sorted(stacks))
		return ;
	while (stacks->stack_a.in_use > 5)
	{
		get_smallest_to_top_ten(stacks);
		ft_pb(stacks);
	}
	sort_five_or_four(stacks);
	while (stacks->stack_a.in_use != stacks->stack_a.size)
		ft_pa(stacks);
}