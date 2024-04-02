#include "../includes/push_swap.h"

int		binary_limit(int r_count)
{
	int i;

	i = 0;
	while (r_count)
	{
		r_count = r_count>>1;
		i++;
	}
	return i;
}

int	elem_in_stack(t_list **stack)
{
	int	i;
	t_list * tmp_stack;

	if (!(* stack))
		return (0);
	tmp_stack = (* stack);
	i = 1;
	while(tmp_stack->next != NULL)
	{
		if (tmp_stack->index != -1)
			i++;
		tmp_stack = tmp_stack->next;
	}
	return (i);
}

int	is_stack_ordered(t_list **stack_a)
{
	t_list *stack_temp;

	stack_temp = (*stack_a);
	while (stack_temp->next != NULL)
	{
		if (stack_temp->next->index != -1)
		{
			if (stack_temp->value < stack_temp->next->value)
				stack_temp = stack_temp->next;
			else
				return (0);
		}
		else
			stack_temp = stack_temp->next;
	}
	return (1);
}

