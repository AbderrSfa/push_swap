/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:48:55 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 13:10:02 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*args_to_string(char **argv)
{
	char	*str;
	char	*temp;
	int		i;

	i = 1;
	str = (char *)malloc(sizeof(char));
	while (argv[i])
	{
		if (!is_arg_valid(argv[i]))
			exit(end_program(1, "Error", NULL));
		temp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (str);
}

char	**init_stacks(char *string, t_stacks *stacks)
{
	char	**args;
	int		size;

	size = 0;
	args = ft_split(string, ' ');
	while (args[size])
		size++;
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.in_use = 0;
	stacks->stack_b.in_use = 0;
	free(string);
	return (args);
}

t_stacks	ft_fill_stacks(char *str)
{
	t_stacks	stacks;
	char		**args;
	long		num;
	int			i;

	i = 0;
	args = init_stacks(str, &stacks);
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit(end_program(1, "Error", &stacks));
		if (!duplicate_arg(&stacks, num))
			exit(end_program(1, "Error", &stacks));
		stacks.stack_a.array[i] = num;
		stacks.stack_a.in_use++;
		free(args[i]);
		i++;
	}
	free(args);
	return (stacks);
}
