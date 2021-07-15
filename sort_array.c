/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:53:39 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:54:42 by asfaihi          ###   ########.fr       */
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

int	*init_array(t_stacks *stacks)
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

int	*sort_array(t_stacks *stacks)
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
