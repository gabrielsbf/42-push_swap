#include "../includes/push_swap.h"

void	*swap_stack(t_list *stack)
{
	t_list	*first_to;
	t_list	*head;
	t_list	*first;

	first = stack;
	head = 	stack->next;
	first_to = stack->next->next;
	first->next = first_to;
	head->next = first;
	stack = head;
	return (void *)stack;

}

void	swap_both_stack(t_list *a, t_list *b)
{
	a = swap_stack(a);
	b = swap_stack(b);

}
void	*push_stack(t_list *from, t_list *to)
{
	
}

// void	*rotate_stack(t_list *stack)
// {}

// void	*rotate_both_stack(t_list *a, t_list *b)
// {}

// void	*reverse_rotate_stack(t_list *stack)
// {}

// void	*reverse_rotate_both_stack(t_list *a, t_list *b)
// {}
