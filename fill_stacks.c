/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:48:55 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:48:56 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int argc, t_stacks *stacks)
{
	int			size;

	size = argc - 1;
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.in_use = 0;
	stacks->stack_b.in_use = 0;
}

t_stacks	ft_fill_stacks(int argc, char **argv)
{
	t_stacks	stacks;
	long		num;
	int			i;

	i = 0;
	init_stacks(argc, &stacks);
	argv++;
	while (*argv)
	{
		num = ft_atoi(*argv);
		if (num < INT_MIN || num > INT_MAX)
			exit(end_program(1, "Error", &stacks));
		if (!duplicate_arg(&stacks, num))
			exit(end_program(1, "Error", &stacks));
		stacks.stack_a.array[i] = num;
		stacks.stack_a.in_use++;
		argv++;
		i++;
	}
	return (stacks);
}
