/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderr_sfa <abderr_sfa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:04:37 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/14 18:41:06 by abderr_sfa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		*init_array(t_stacks *stacks)
{
	int		i;
	int		*arr;

	i = 0;
	arr = malloc(sizeof(int) * stacks->stack_a.size);
	while (i < stacks->stack_a.size)
	{
		arr[i] = stacks->stack_a.array[i];
		i++;
	}
	return (arr);
}

int		*sort_array(t_stacks *stacks)
{
	int		i;
	int		j;
	int		smallest_index;
	int		*sorted_array;

	i = 0;
	sorted_array = init_array(stacks);
	while (i < stacks->stack_a.size - 1)
	{
		smallest_index = i;
		j = i + 1;
		while (j < stacks->stack_a.size)
		{
			if (sorted_array[j] < sorted_array[smallest_index])
				smallest_index = j;
			j++;
		}
		swap_values(&sorted_array[smallest_index], &sorted_array[i]);
		i++;
	}
	return (sorted_array);
}

int		get_number_within_chunk(t_stacks *stacks, int chunk_endpoint)
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
				break;
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

int		get_chunk_endpoint(int *sorted_array, int size, int part, int chunk)
{
	int		chunk_endpoint;

	chunk_endpoint = sorted_array[(size * part) / chunk];
	return (chunk_endpoint);
}

void	sort_rest_of_numbers(t_stacks *stacks, int used_size)
{
	if (!stack_is_sorted(stacks))
	{
		while (stacks->stack_a.in_use >= 5)
		{
			get_smallest_to_top_ten(stacks);
			ft_pb(stacks);
		}
		sort_four_or_five(stacks);
		while (stacks->stack_a.in_use != used_size)
			ft_pa(stacks);
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
		chunk_endpoint = get_chunk_endpoint(sorted_array, stacks->stack_a.size, i, 4);
		move_to_b(stacks, chunk_endpoint);
		i++;
	}
	free(sorted_array);
	sort_rest(stacks);
	while (stacks->stack_b.in_use != 0)
	{
		get_biggest_to_top(stacks);
		ft_pa(stacks);
	}
}