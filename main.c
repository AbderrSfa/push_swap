/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:35 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 13:09:58 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("/**************************stack_a*************************/\n");
	while (i < stacks->stack_a.in_use)
		printf("|stack_a size = %d|\t|size used = %d|\t|num = %d|\n",stacks->stack_a.size, stacks->stack_a.in_use,  stacks->stack_a.array[i++]);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*str;

	if (argc == 1)
		return (0);
	str = args_to_string(argv);
	stacks = ft_fill_stacks(str);
	if (stack_is_sorted(&stacks))
		exit(end_program(0, NULL, &stacks));
	if (stacks.stack_a.size == 2)
		ft_sa(&stacks, PRINT);
	else if (stacks.stack_a.size == 3)
		sort_three_numbers(&stacks);
	else if (stacks.stack_a.size == 4 || stacks.stack_a.size == 5)
		sort_four_or_five(&stacks);
	else if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		sort_six_to_ten(&stacks);
	else if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		sort_one_hundred(&stacks);
	else if (stacks.stack_a.size > 100)
		sort_five_hundred(&stacks);
	////
	//print_stack(&stacks);
	////
	return (end_program(0, NULL, &stacks));
}
