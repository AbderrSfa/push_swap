/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:35 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/13 12:16:44 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	printf("/*****************************stack_a****************************/\n");
	while (i < stacks->stack_a.in_use)
		printf("|stack_a size= %d|\t|size used = %d|\t|num = %d|\n",stacks->stack_a.size, stacks->stack_a.in_use,  stacks->stack_a.array[i++]);

	printf("/*****************************stack_b****************************/\n");
	i = 0;
	while (i < stacks->stack_b.in_use)
		printf("|stack_b size = %d|\t|size used = %d|\t|num = %d|\n",stacks->stack_b.size, stacks->stack_b.in_use, stacks->stack_b.array[i++]);
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (!are_args_valid(argv))
		exit(end_program(1, "Error", NULL));
	stacks = ft_fill_stacks(argc, argv);
	if (stack_is_sorted(&stacks))
		exit(end_program(0, NULL, &stacks));
	print_stacks(&stacks);
	if (stacks.stack_a.size == 2)
		ft_sa(&stacks, PRINT);
	else if (stacks.stack_a.size == 3)
		sort_three_numbers(&stacks);
	else if (stacks.stack_a.size == 4 || stacks.stack_a.size == 5)
		sort_five_or_four(&stacks);
	else if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		sort_six_to_ten(&stacks);
	else if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		sort_one_hundred(&stacks);
	print_stacks(&stacks);
	return (0);
}