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

#include "../../includes/push_swap.h"

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

int	*malloc_from_args(char *argv[], int *r_count)
{
	size_t	i;
	int		nv;
	int		verificator;
	int		*values;

	verificator = *r_count;
	i = 0;
	nv = 1;
	while (nv <= verificator)
	{
		while (i < ft_strlen(argv[nv]))
		{
			i = get_next_n(argv[nv], i);
			*r_count = *r_count + 1;
		}
		*r_count = *r_count - 1;
		nv++;
		i = 0;
	}
	values = (int *)malloc((*r_count) * sizeof(int));
	if (!values)
		return (NULL);
	return (values);
}

int	*format_args(char *argv[], int *r_count)
{
	int	start_i;
	int	arg_number;
	int	nv;
	int	*stack_values;

	arg_number = *r_count;
	stack_values = malloc_from_args(argv, r_count);
	nv = 1;
	start_i = 0;
	while (nv <= arg_number)
	{
		while (argv[nv][start_i] != '\0')
		{
			*stack_values = ft_atoi_free_ptr(ft_substr(argv[nv], start_i,
						get_next_n(argv[nv], start_i)));
			start_i = get_next_n(argv[nv], start_i);
			stack_values++;
		}
		nv++;
		start_i = 0;
	}
	stack_values = stack_values - *r_count;
	return (stack_values);
}

int	get_next_n(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (ft_strchr("+-0123456789", str[i]) == 0)
		{
			while (ft_has_space(str, i) && (str[i] != '\0'))
				i++;
			if (str[i] != '\0' && !(ft_has_space(str, i)))
				return (i);
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

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
	if (r_count <= 3)
		op_three_vls(&stack_a, r_count);
	else if (r_count > 3 && r_count <= 5)
		op_fv_vls(&stack_a, &stack_b);
	else
		more_than_five(&stack_a, &stack_b, r_count);
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}