#include "push_swap.h"

int		ft_put_error(int ret, char *message, t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a.array)
			free(stacks->stack_a.array);
		if (stacks->stack_b.array)
			free(stacks->stack_b.array);
	}
	if (message)
	{
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (ret);
}

int		are_args_valid(char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		duplicate_arg(t_stacks *stacks, int num)
{
	int		i;

	i = 0;
	while (i < stacks->stack_a.size_used)
	{
		if (num == stacks->stack_a.array[i])
			return (0);
		i++;
	}
	return (1);
}

int		stack_is_sorted(t_stacks *stacks)
{
	int		i;
	int		temp;

	i = 0;
	while (i < stacks->stack_a.size - 1)
	{
		if (stacks->stack_a.array[i] > stacks->stack_a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	init_stacks(int argc, t_stacks *stacks)
{
	int			size;

	size = argc - 1;
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.size_used = 0;
	stacks->stack_b.size_used = 0;
}

t_stacks	ft_fill_stacks(int argc, char **argv)
{
	t_stacks	stacks;
	long		num;
	int			i;

	i = 0;
	init_stacks(argc, &stacks);
	argv++;
	while (*argv)
	{
		num = ft_atoi(*argv);
		if (num < INT_MIN || num > INT_MAX)
			exit(ft_put_error(1, "Error", &stacks));
		if (!duplicate_arg(&stacks, num))
			exit(ft_put_error(1, "Error", &stacks));
		stacks.stack_a.array[i] = num;
		stacks.stack_a.size_used++;
		argv++;
		i++;
	}
	return (stacks);
}