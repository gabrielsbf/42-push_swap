#include "../includes/push_swap.h"

void	swap_stack(t_list **stack)
{
	t_list	*first_to;
	t_list	*head;
	t_list	*first;

	first = *stack;
	head = 	(*stack)->next;
	first_to = (*stack)->next->next;
	first->next = first_to;
	head->next = first;
	(*stack) = head;
}

void	swap_both_stack(t_list **a, t_list **b)
{
	swap_stack(a);
	swap_stack(b);
}
void	push_stack(t_list **from, t_list **to)
{
	t_list	*head;

	head = (*from)->next;
	(*from)->next = (*to);
	(*to) = (*from);
	(*from) = head;
}

void	rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*first_stack;

	head = (*stack)->next;
	first_stack = (*stack);
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = first_stack;
	(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = head;
}

void	rotate_both_stack(t_list **a, t_list **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_list **stack)
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
}

void	reverse_rotate_both_stack(t_list **a, t_list **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
