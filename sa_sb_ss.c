/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:35:10 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 10:38:45 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stacks, int print)
{
	int		temp;

	temp = 0;
	if (print == PRINT)
		ft_putendl_fd("sa", 1);
	if (stacks->stack_a.in_use > 1)
	{
		temp = stacks->stack_a.array[0];
		stacks->stack_a.array[0] = stacks->stack_a.array[1];
		stacks->stack_a.array[1] = temp;
	}
}

void	ft_sb(t_stacks *stacks, int print)
{
	int		temp;

	temp = 0;
	if (print == PRINT)
		ft_putendl_fd("sb", 1);
	if (stacks->stack_b.in_use > 1)
	{
		temp = stacks->stack_b.array[0];
		stacks->stack_b.array[0] = stacks->stack_b.array[1];
		stacks->stack_b.array[1] = temp;
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_putendl_fd("ss", 1);
	ft_sa(stacks, NO_PRINT);
	ft_sb(stacks, NO_PRINT);
}
