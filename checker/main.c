/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:10:30 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/15 17:23:54 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char		*line;
	t_stacks	stacks;
	char		*str;
	int			ret;

	if (argc == 1)
		return (0);
	str = args_to_string(argv);
	stacks = ft_fill_stacks(str);
	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_select_instruction(line, &stacks);
		free(line);
	}
	free(line);
	if (stack_is_sorted(&stacks) && !stacks.stack_b.in_use)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (end_program(0, NULL, &stacks));
}