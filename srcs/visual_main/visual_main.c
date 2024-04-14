/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:50 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 14:36:11 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visual_opt.h"

int	main(int argc, char *argv[])
{
	int		r_count;
	int		*values;
	t_list	*stack_a;
	t_list	*stack_b;

	r_count = argc - 1;
	if (argc == 1 || validate_args(argv, argc) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	values = format_args(argv, &r_count);
	create_stack_a(&stack_a, values, r_count);
	create_stack_b(&stack_b);
	print_stack(&stack_a, "\nstack BEFORE\n---------\nBEGIN OPERATIONS\n");
	if (r_count <= 3)
		op_three_vls(&stack_a, r_count);
	else if (r_count > 3 && r_count <= 5)
		op_fv_vls(&stack_a, &stack_b);
	else
		more_than_five(&stack_a, &stack_b, r_count);
	print_stack(&stack_a, "\nstack após ordenação\n---------\n");
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}
