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

void	op_six_vls(t_list **stack_a, t_list **stack_b, int s_count)
{
	int		i;
	t_list	*end_stack_a;

	end_stack_a = (*stack_a);
	i = 1;
	if (verify_stack_order(stack_a))
		return ;
	// ft_printf("not ordered on verify\n");
	while(i < s_count)
	{
		// ft_printf("i is : %d\n", i);
		end_stack_a = end_stack_a->next;
		i++;
		// ft_printf("end_stack_a_value : %d\n", end_stack_a->value);
	}
	while (i > 3)
	{
		// ft_printf("entered_here\ni value is: %d\n", i);
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_stack(stack_a, 'a');
		if ((*stack_a)->value > end_stack_a->value)
			reverse_rotate_stack(stack_a, 'a');
		push_stack(stack_a, stack_b, 'a');
		i--;
	}
	// ft_printf("out of while\ni value is: %d\n", i);
	// ft_printf("value of s_count - i is: %d\n", s_count - i);
	op_three_vls(stack_a, i);
	while (s_count - i != 0)
	{
		push_stack(stack_b, stack_a, 'b');
		i++;
	}
	if (!verify_stack_order(stack_a))
		op_six_vls(stack_a, stack_b, s_count);
}

int	verify_stack_order(t_list **stack_a)
{
	// ft_printf("value of stack a is \n");
	// print_stack((*stack_a));
	t_list *stack_temp;

	stack_temp = (*stack_a);
	while(stack_temp->next != NULL)
	{
		if (stack_temp->value <= stack_temp->next->value)
			stack_temp = stack_temp->next;
		else
			return (0);
	}
	return (1);
}
