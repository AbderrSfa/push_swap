/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:46:30 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/16 15:34:38 by asfaihi          ###   ########.fr       */
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

int	is_arg_valid(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && !(ft_isdigit(str[i])))
			return (0);
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
			return (0);
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

	i = 0;
	while (i < stacks->stack_a.size - 1)
	{
		if (stacks->stack_a.array[i] > stacks->stack_a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
