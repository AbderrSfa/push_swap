/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:38 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 11:32:06 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_smallest_index(t_stacks *stacks)
{
	int		i;
	int		smallest_index;

	i = 0;
	smallest_index = 0;
	while (i < stacks->stack_a.in_use)
	{
		if (stacks->stack_a.array[i] < stacks->stack_a.array[smallest_index])
			smallest_index = i;
		i++;
	}
	return (smallest_index);
}

void	get_smallest_to_top_five(t_stacks *stacks)
{
	int		smallest_index;

	smallest_index = get_smallest_index(stacks);
	while (smallest_index != 0)
	{
		if (smallest_index > 2)
			ft_rra(stacks, PRINT);
		else
			ft_ra(stacks, PRINT);
		smallest_index = get_smallest_index(stacks);
	}
}

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

void	sort_three_numbers(t_stacks *stacks)
{
	int		*array;

	array = stacks->stack_a.array;
	if (stack_is_sorted(stacks))
		return ;
	if (array[0] > array[1] && array[0] < array[2] && array[1] < array[2])
		ft_sa(stacks, PRINT);
	else if (array[0] < array[1] && array[1] > array[2] && array[0] > array[2])
		ft_rra(stacks, PRINT);
	else if (array[0] > array[1] && array[0] > array[2] && array[1] < array[2])
		ft_ra(stacks, PRINT);
	else if (array[0] > array[1] && array[1] > array[2])
	{
		ft_ra(stacks, PRINT);
		ft_sa(stacks, PRINT);
	}
	else if (array[0] < array[1] && array[1] > array[2] && array[0] < array[2])
	{
		ft_rra(stacks, PRINT);
		ft_sa(stacks, PRINT);
	}
}

void	sort_five_or_four(t_stacks *stacks)
{
	if (stack_is_sorted(stacks))
		return ;
	while (stacks->stack_a.in_use > 3)
	{
		get_smallest_to_top_five(stacks);
		ft_pb(stacks);
	}
	sort_three_numbers(stacks);
	while (stacks->stack_a.in_use != stacks->stack_a.size)
		ft_pa(stacks);
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