/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:46 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 14:35:06 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	create_stack_a(t_list **stack, int	*s_values, int c_args)
{
	t_list	*iter_stack;
	t_list	*return_stack;
	int		i;
	int		index;

	index = 0;
	i = 0;
	iter_stack = (t_list *)malloc(sizeof(t_list));
	if (!iter_stack)
		return ;
	return_stack = iter_stack;
	while (i < c_args)
	{
		iter_stack->value = s_values[i];
		index++;
		i++;
		if (i == c_args)
			break ;
		iter_stack->next = (t_list *)malloc(sizeof(t_list));
		iter_stack = iter_stack->next;
	}
	free(s_values);
	iter_stack->next = NULL;
	set_stack_indexes(&return_stack);
	(*stack) = return_stack;
}

void	create_stack_b(t_list **stack)
{
	t_list	*return_stack;

	return_stack = (t_list *)malloc(sizeof(t_list));
	return_stack->next = NULL;
	return_stack->index = -1;
	(*stack) = return_stack;
}

void	set_stack_indexes(t_list **stack)
{
	t_list	*stack_iter;

	stack_iter = (*stack);
	while (stack_iter->next != NULL)
	{
		stack_iter->index = get_index(stack, stack_iter->value);
		stack_iter = stack_iter->next;
	}
	stack_iter->index = get_index(stack, stack_iter->value);
}

int	get_index(t_list **stack, int value)
{
	t_list	*stack_temp;
	int		i;

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

void	destroy_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_stack_a;

	while ((*stack_a)->next != NULL)
	{
		temp_stack_a = (*stack_a);
		*stack_a = (*stack_a)->next;
		free(temp_stack_a);
	}
	free((*stack_a));
	free((*stack_b));
}
