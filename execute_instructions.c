/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:11:12 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/16 11:18:47 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_instruction(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa"))
		ft_sa(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "sb"))
		ft_sb(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "ss"))
		ft_ss(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "pa"))
		ft_pa(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "pb"))
		ft_pb(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "ra"))
		ft_ra(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "rb"))
		ft_rb(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "rr"))
		ft_rr(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "rra"))
		ft_rra(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrb(stacks, NO_PRINT);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(stacks, NO_PRINT);
	else
		exit(end_program(1, "Error", stacks));
}
