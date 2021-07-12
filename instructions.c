#include "push_swap.h"

void	ft_sa(t_stacks *stacks, int print)
{
	int		temp;

	temp = 0;
	if (print == ON)
		ft_putendl_fd("sa", 1);
	if (stacks->stack_a.size_used > 1)
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
	if (print == ON)
		ft_putendl_fd("sb", 1);
	if (stacks->stack_b.size_used > 1)
	{
		temp = stacks->stack_b.array[0];
		stacks->stack_b.array[0] = stacks->stack_b.array[1];	
		stacks->stack_b.array[1] = temp;
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_putendl_fd("sb", 1);
	ft_sa(stacks, OFF);
	ft_sb(stacks, OFF);
}