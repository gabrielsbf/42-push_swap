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
	t_list *stack_b;
	if (argc == 1)
	{
		ft_printf("\nError\n");
		return (0);
	}
	stack_a = create_stack_a(argv, argc);
	stack_b = create_stack_b();
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("pós_swap_a\n");
	stack_a = swap_stack(stack_a);

	print_stack(stack_a);
	return (0);
}
