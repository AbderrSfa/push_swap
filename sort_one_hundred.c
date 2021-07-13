/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:04:37 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 13:18:54 by asfaihi          ###   ########.fr       */
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

void	move_to_top(t_stacks *stacks, int chunk_endpoint)
{
	
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
}