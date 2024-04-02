#include "../includes/push_swap.h"

void	op_three_vls(t_list **stack_a, int s_count)
{
	if (s_count == 3)
	{
		if((*stack_a)->value > (*stack_a)->next->value)
			swap_stack(stack_a, 'a');
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			reverse_rotate_stack(stack_a, 'a');
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			reverse_rotate_stack(stack_a, 'a');
			swap_stack(stack_a, 'a');
		}
	}
	if(s_count == 2)
	{
		if((*stack_a)->value > (*stack_a)->next->value)
		swap_stack(stack_a, 'a');
	}
}

void	op_fv_vls(t_list **stack_a, t_list **stack_b)
{
	if (is_stack_ordered(stack_a))
		return ;
	while (elem_in_stack(stack_a) > 3)
	{
		while (elem_in_stack(stack_a) > 3 && ((* stack_a)->index == 1 || (* stack_a)->index == 0))
			push_stack(stack_a, stack_b, 'a');
		if (elem_in_stack(stack_a) > 3)
			reverse_rotate_stack(stack_a, 'a');
	}
	if ((*stack_b)->index == 0 && (*stack_b)->next->index == 1)
		swap_stack(stack_b, 'b');
	op_three_vls(stack_a, elem_in_stack(stack_a));
	while (elem_in_stack(stack_b) != 0 && (* stack_b)->index != -1)
		push_stack(stack_b, stack_a, 'b');
}

void	more_than_five(t_list **stack_a, t_list **stack_b, int s_count)
{
	int	iter;
	int	begin;

	begin = 0;
	iter = binary_limit(s_count);
	while (iter > 0)
	{
		order_by_radix(stack_a, stack_b, begin, s_count);
		iter--;
		begin++;
	}
	while (elem_in_stack(stack_b) > 0)
	{
		push_stack(stack_b, stack_a, 'b');
	}
}

void	order_by_radix(t_list **stack_a, t_list **stack_b, int ind, int count)
{
	int	count_b;
	int	count_a;

	count_b = elem_in_stack(stack_b);
	while (count_b > 0 && (*stack_b)->next != NULL)
	{
		if (((* stack_b)->index >> ind & 1) == 1)
			push_stack(stack_b, stack_a, 'b');
		else
			rotate_stack(stack_b, 'b');
		count_b--;
	}
	count_a = elem_in_stack(stack_a);
	while (count_a >= 0 &&(*stack_a)->next != NULL)
	{
		if (((* stack_a)->index >> ind & 1) == 0)
			push_stack(stack_a, stack_b, 'a');
		else
			rotate_stack(stack_a, 'a');
		count_a--;
	}
}

