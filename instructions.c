#include "push_swap.h"

void	ft_sa(t_stacks *stacks, int print)
{
	int		temp;

	temp = 0;
	if (print == ON)
		ft_putendl_fd("sa", 1);
	if (stacks->stack_a.in_use > 1)
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
	if (stacks->stack_b.in_use > 1)
	{
		temp = stacks->stack_b.array[0];
		stacks->stack_b.array[0] = stacks->stack_b.array[1];	
		stacks->stack_b.array[1] = temp;
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_putendl_fd("ss", 1);
	ft_sa(stacks, OFF);
	ft_sb(stacks, OFF);
}

void	push_stack_down(int *array, int in_use)
{
	while (in_use > 0)
	{
		array[in_use] = array[in_use - 1];
		in_use--;
	}
}

void	pop_stack_up(int *array, int in_use)
{
	int		i;

	i = 0;
	while (i < in_use)
	{
		array[i] = array[i + 1];
		i++;
	}
}

void	ft_pb(t_stacks *stacks)
{
	int		i;

	i = 0;
	ft_putendl_fd("pb", 1);
	if (stacks->stack_a.in_use == 0)
		return ;
	if (stacks->stack_b.in_use == 0)
		stacks->stack_b.array[0] = stacks->stack_a.array[0];
	else
	{
		push_stack_down(stacks->stack_b.array, stacks->stack_b.in_use);
		stacks->stack_b.array[0] = stacks->stack_a.array[0];
	}
	pop_stack_up(stacks->stack_a.array, stacks->stack_a.in_use);
	stacks->stack_b.in_use++;
	stacks->stack_a.in_use--;
}

void	ft_pa(t_stacks *stacks)
{
	int		i;

	i = 0;
	ft_putendl_fd("pa", 1);
	if (stacks->stack_b.in_use == 0)
		return ;
	if (stacks->stack_a.in_use == 0)
		stacks->stack_a.array[0] = stacks->stack_b.array[0];
	else
	{
		push_stack_down(stacks->stack_a.array, stacks->stack_a.in_use);
		stacks->stack_a.array[0] = stacks->stack_b.array[0];
	}
	pop_stack_up(stacks->stack_b.array, stacks->stack_b.in_use);
	stacks->stack_a.in_use++;
	stacks->stack_b.in_use--;
}

void	ft_rb(t_stacks *stacks, int print)
{
	int		temp;

	if (print == ON)
	ft_putendl_fd("rb", 1);
	temp = stacks->stack_b.array[0];
	pop_stack_up(stacks->stack_b.array, stacks->stack_b.in_use);
	stacks->stack_b.array[stacks->stack_b.in_use - 1] = temp;
}

void	ft_ra(t_stacks *stacks, int print)
{
	int		temp;

	if (print == ON)
		ft_putendl_fd("ra", 1);
	temp = stacks->stack_a.array[0];
	pop_stack_up(stacks->stack_a.array, stacks->stack_a.in_use);
	stacks->stack_a.array[stacks->stack_a.in_use - 1] = temp;
}

void	ft_rr(t_stacks *stacks)
{
	ft_putendl_fd("rr", 1);
	ft_ra(stacks, OFF);
	ft_rb(stacks, OFF);
}
