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

		// if((*stack_a)->value > (*stack_a)->next->value)
		// 	swap_stack(stack_a);
	}
	if(s_count == 2)
	{
		if((*stack_a)->value > (*stack_a)->next->value)
		swap_stack(stack_a, 'a');
	}
}
