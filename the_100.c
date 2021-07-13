/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:20:02 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 16:41:52 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*ft_list_init(t_array *stack_a)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		sorted_list[i] = stack_a->array[i];
		i++;
	}
	return (sorted_list);
}

int	*ft_sort_array(t_array *stack_a)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_list;

	i = 0;
	sorted_list = ft_list_init(stack_a);
	while (i < stack_a->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
			j++;
		}
		ft_swap(&sorted_list[min_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

int	ft_find_key_number(int *sorted_list, int size, int divided, int chunks)
{
	int	key_munber;

	key_munber = sorted_list[(size * divided) / chunks];
	return (key_munber);
}

int	ft_search_index(t_stacks *stacks, int key_number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.in_use)
	{
		if (stacks->stack_a.array[i] <= key_number)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_to_top(t_stacks *stacks, int index)
{
	int	divid;

	divid = stacks->stack_a.in_use / 2;
	while (index != 0)
	{
		if (index <= divid)
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

void	ft_push_index(t_stacks *stacks, int key_number)
{
	int	index;

	index = ft_search_index(stacks, key_number);
	while (index != -1)
	{
		ft_move_to_top(stacks, index);
		ft_pb(stacks);
		index = ft_search_index(stacks, key_number);
	}
}

int	ft_get_smallest_index(t_array *stack_a)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < stack_a->in_use)
	{
		if (stack_a->array[s_index] > stack_a->array[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	ft_find_smallest_number_ten(t_stacks *stacks)
{
	int	s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ft_ra(stacks, PRINT);
		else
			ft_rra(stacks, PRINT);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_rest_of_numbers(t_stacks *stacks, int size)
{
	if (!stack_is_sorted(stacks))
	{
		while (stacks->stack_a.in_use >= 5)
		{
			ft_find_smallest_number_ten(stacks);
			ft_pb(stacks);
		}
		sort_four_or_five(stacks);
		while (stacks->stack_a.in_use != size)
			ft_pa(stacks);
	}
}

void	ft_sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.in_use == 2)
	{
		if (!stack_is_sorted(stacks))
			ft_sa(stacks, PRINT);
	}
	if (stacks->stack_a.in_use == 3)
		sort_three_numbers(stacks);
	if (stacks->stack_a.in_use == 5 || stacks->stack_a.in_use == 4)
		sort_four_or_five(stacks);
	if (stacks->stack_a.in_use > 5)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.in_use);
}

void 	ft_sort_more_then_handred(t_stacks *stacks)
{
	if (stacks->stack_a.in_use == 2)
	{
		if (!stack_is_sorted(stacks))
			ft_sa(stacks, PRINT);
	}
	else if (stacks->stack_a.in_use == 3)
		sort_three_numbers(stacks);
	else if (stacks->stack_a.in_use == 5 || stacks->stack_a.in_use == 4)
		sort_four_or_five(stacks);
	else if (stacks->stack_a.in_use > 5 && stacks->stack_a.in_use <= 10)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.in_use);
	else if (stacks->stack_a.in_use > 10)
		ft_one_handred(stacks);
}

int	ft_get_biggest_index(t_array *stack_b)
{
	int	i;
	int	b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->in_use)
	{
		if (stack_b->array[b_index] < stack_b->array[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	ft_find_biggest_number(t_stacks *stacks)
{
	int	b_index;

	b_index = ft_get_biggest_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.in_use / 2))
			ft_rb(stacks, PRINT);
		else
			ft_rrb(stacks, PRINT);
		b_index = ft_get_biggest_index(&stacks->stack_b);
	}
}

void	ft_one_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 4)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 4);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_rest(stacks);
	while (stacks->stack_b.in_use != 0)
	{
		ft_find_biggest_number(stacks);
		ft_pa(stacks);
	}
}

void	ft_five_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 8)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 8);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_more_then_handred(stacks);
	while (stacks->stack_b.in_use != 0)
	{
		ft_find_biggest_number(stacks);
		ft_pa(stacks);
	}
}
