#include "../includes/push_swap.h"

void	get_stack_indexes(t_list **stack)
{
	t_list	*stack_iter;

	stack_iter = (* stack);
	while(stack_iter->next != NULL)
	{
		stack_iter->index = get_index(stack, stack_iter->value);
		stack_iter = stack_iter->next;
	}
	stack_iter->index = get_index(stack, stack_iter->value);
}

int	get_index(t_list **stack, int value)
{
	t_list	*stack_temp;
	int	i;

	stack_temp = *stack;
	i = 0;
	while (stack_temp->next != NULL)
	{
		if (value > stack_temp->value)
			i++;
		stack_temp = stack_temp->next;
	}
	if (value > stack_temp->value)
		i++;
	return (i);
}
