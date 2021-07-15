/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:46:30 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:47:14 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_program(int ret, char *error, t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a.array)
			free(stacks->stack_a.array);
		if (stacks->stack_b.array)
			free(stacks->stack_b.array);
	}
	if (error)
		ft_putendl_fd(error, 2);
	return (ret);
}

int	are_args_valid(char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate_arg(t_stacks *stacks, int num)
{
	int		i;

	i = 0;
	while (i < stacks->stack_a.in_use)
	{
		if (num == stacks->stack_a.array[i])
			return (0);
		i++;
	}
	return (1);
}

int	stack_is_sorted(t_stacks *stacks)
{
	int		i;
	int		temp;

	i = 0;
	while (i < stacks->stack_a.size - 1)
	{
		if (stacks->stack_a.array[i] > stacks->stack_a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
