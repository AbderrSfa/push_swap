#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	printf("/*****************************stack_a****************************/\n");
	while (i < stacks->stack_a.size_used)
		printf("|stack_a size= %d|\t|size used = %d|\t|num = %d|\n",stacks->stack_a.size, stacks->stack_a.size_used,  stacks->stack_a.array[i++]);

	printf("/*****************************stack_b****************************/\n");
	i = 0;
	while (i < stacks->stack_b.size_used)
		printf("|stack_b size = %d|\t|size used = %d|\t|num = %d|\n",stacks->stack_b.size, stacks->stack_b.size_used, stacks->stack_b.array[i++]);
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (!are_args_valid(argv))
		exit(ft_put_error(1, "Error", NULL));
	stacks = ft_fill_stacks(argc, argv);
	if (stack_is_sorted(&stacks))
		exit(ft_put_error(0, NULL, &stacks));
	print_stacks(&stacks);
	if (stacks.stack_a.size == 2)
		ft_sa(&stacks, ON);
	print_stacks(&stacks);
	return (0);
}