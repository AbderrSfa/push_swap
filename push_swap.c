#include "push_swap.h"

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
	return (end_program(0, NULL, &stacks));
}