/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:50 by gabrfern          #+#    #+#             */
/*   Updated: 2024/02/29 16:16:51 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_list *stack)
{
	ft_printf("printando valores\n--------------\n\n");
	t_list *temp_stack;
	int	index;

	temp_stack = stack;
	index = 0;
	while(temp_stack->next)
	{
		ft_printf("valor da temp_stack a no index: %d é %d\n", index, temp_stack->value);
		temp_stack = temp_stack->next;
		index++;
	}
	if(temp_stack->value)
		ft_printf("valor da temp_stack a no index: %d é %d\n", index, temp_stack->value);
}

int	main(int argc, char *argv[])
{
	t_list *stack_a;
	// t_list *stack_b;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	create_stack_a(&stack_a, argv, argc);
	// create_stack_b(&stack_b);

	reverse_rotate_stack(&stack_a);
	ft_printf("\nstack a\n");
	print_stack(stack_a);
	// ft_printf("\nstack b\n");
	// print_stack(stack_b);

	return (0);
}
