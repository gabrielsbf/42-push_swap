/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:50 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 14:35:21 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list **st_a, t_list **st_b, int count, int *vls)
{
	create_stack_a(st_a, vls, count);
	create_stack_b(st_b);
	if (count <= 3)
		op_three_vls(st_a, count);
	else if (count > 3 && count <= 5)
		op_fv_vls(st_a, st_b);
	else
		more_than_five(st_a, st_b, count);
	destroy_stacks(st_a, st_b);
}

int	main(int argc, char *argv[])
{
	int		r_count;
	int		*values;
	t_list	*stack_a;
	t_list	*stack_b;

	r_count = argc - 1;
	if (argc == 1 || validate_args(argv, argc) == 0)
		ft_printf("Error\n");
	else
	{
		values = format_args(argv, &r_count);
		if (!allowed_cond(argv, argc, values, r_count))
		{
			ft_printf("Error\n");
			free(values);
		}
		else
			push_swap(&stack_a, &stack_b, r_count, values);
	}
	return (0);
}
