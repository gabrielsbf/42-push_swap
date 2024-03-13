/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:46 by gabrfern          #+#    #+#             */
/*   Updated: 2024/02/29 16:16:47 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	create_stack_a(t_list **stack, char	*args[], int c_args)
{
	t_list *iter_stack;
	t_list *return_stack;
	int	i;
	int	index;

	index = 0;
	i = 1;
	iter_stack = (t_list *)malloc(sizeof(t_list));
	if (!iter_stack)
		return ;
	return_stack = iter_stack;
	while(i < c_args)
	{
		iter_stack->value = ft_atoi(args[i]);
		iter_stack->index = index;
		index++;
		i++;
		if(i == c_args)
			break ;
		iter_stack->next = (t_list *)malloc(sizeof(t_list));
		iter_stack = iter_stack->next;
	}
	iter_stack->next = NULL;
	(*stack) = return_stack;
}

void	create_stack_b(t_list **stack)
{
	t_list	*return_stack;
	return_stack = (t_list *)malloc(sizeof(t_list));
	return_stack->next = NULL;
	(*stack) = return_stack;
}
