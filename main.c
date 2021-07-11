#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	printf("/*****************************stack_a****************************/\n");
	while (i < stacks->stack_a.size_used)
	{
		printf("|size of stack_a= %d|used size = %d|value = %d|\n",stacks->stack_a.size, stacks->stack_a.size_used,  stacks->stack_a.array[i]);
		i++;
	}

	printf("/*****************************stack_b****************************/\n");
	i = 0;
	while (i < stacks->stack_b.size_used)
	{
		printf("|size of stack_b = %d|used size = %d|value = %d|\n",stacks->stack_b.size, stacks->stack_b.size_used, stacks->stack_b.array[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (!are_args_valid(argv))
		exit(ft_put_error("Error", NULL));
	stacks = ft_fill_stacks(argc, argv);
	print_stacks(&stacks);
	return (0);
}