/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:38 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/12 17:08:39 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
