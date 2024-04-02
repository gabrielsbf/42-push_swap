#include "../includes/push_swap.h"

void	swap_stack(t_list **stack, char stack_name)
{
	t_list	*first_to;
	t_list	*head;
	t_list	*first;

	if (elem_in_stack(stack) <= 1)
		return ;
	first = *stack;
	head = 	(*stack)->next;
	first_to = (*stack)->next->next;
	first->next = first_to;
	head->next = first;
	(*stack) = head;
	if(stack_name != 0)
		ft_printf("s%c\n", stack_name);
}

void	swap_both_stack(t_list **a, t_list **b)
{
	if (elem_in_stack(a) <= 0 || elem_in_stack(b) <= 0)
		return ;
	swap_stack(a, 0);
	swap_stack(b, 0);
	ft_printf("ss\n");

}
void	push_stack(t_list **from, t_list **to, char stack_from)
{
	t_list	*head;
	if (elem_in_stack(from) <= 0)
		return ;
	head = (*from)->next;
	(*from)->next = (*to);
	(*to) = (*from);
	(*from) = head;
	ft_printf("p%c\n", stack_from);
}

void	rotate_stack(t_list **stack, char stack_name)
{
	t_list	*head;
	t_list	*first_stack;

	// if (elem_in_stack(stack) <= 1)
	// 	return ;
	head = (*stack)->next;
	first_stack = (*stack);
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = first_stack;
	(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = head;
	if(stack_name != 0)
		ft_printf("r%c\n", stack_name);
}

void	rotate_both_stack(t_list **a, t_list **b)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_list **stack, char stack_name)
{
	t_list	*head;
	t_list	*first_stack;

	first_stack = (*stack);
	if ((*stack)->next == NULL)
		return ;
	while ((*stack)->next->next != NULL)
		(*stack) = (*stack)->next;
	head = (*stack)->next;
	head->next = first_stack;
	(*stack)->next = NULL;
	(*stack) = head;
	if(stack_name != 0)
		ft_printf("rr%c\n", stack_name);
}

void	reverse_rotate_both_stack(t_list **a, t_list **b)
{
	reverse_rotate_stack(a, 0);
	reverse_rotate_stack(b, 0);
	ft_printf("rrr\n");
}
