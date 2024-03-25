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
		ft_printf("valor %d index: %d\n", index, temp_stack->value);
		temp_stack = temp_stack->next;
		index++;
	}
	if(temp_stack->value)
		ft_printf("valor %d index: %d\n", index, temp_stack->value);
}

int	*malloc_from_args(char *argv[], int *r_count)
{
	size_t i;
	int	nv;
	int	verificator;
	int	*values;

	verificator = *r_count;
	i = 0;
	nv = 1;
	while(nv <= verificator)
	{
		while(i < ft_strlen(argv[nv]))
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
	while(nv <= arg_number)
	{
		while (argv[nv][start_i]!= '\0')
		{
			*stack_values = ft_atoi(ft_substr(argv[nv], start_i, get_next_n(argv[nv], start_i)));
			start_i = get_next_n(argv[nv], start_i);
			stack_values++;
		}
		nv++;
		start_i = 0;
	}
	stack_values = stack_values - *r_count;
	return (stack_values);
}

int	has_space(char	*str, int i)
{
	if(((str[i]>= 7 && str[i]<= 13)|| str[i] == 32))
		return (1);
	else
		return (0);
}

int	get_next_n(char *str, int i)
{
	while(str[i] != '\0')
	{
		if (ft_strchr("0123456789", str[i]) == 0)
		{
			while(has_space(str, i) && (str[i] != '\0') )
				i++;
			if (str[i] != '\0' && !(has_space(str, i)))
				return (i);
		}
		if(str[i] == '\0')
			break;
		i++;
	}
	return (i);
}

int	validate_args(char *argv[], int argc)
{
	int	i;
	int	nv;

	nv = 1;
	i = 0;
	while (nv < argc)
	{
		while (argv[nv][i]!= '\0')
		{
			if (ft_strchr("0123456789",argv[nv][i]) == 0)
			{
				if (!(has_space(argv[nv], i)) && (argv[nv][i] != '\0'))
					return (0);
			}
			i++;
		}
		nv++;
		i = 0;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	r_count;
	int	*values;

	r_count = argc - 1;
	t_list	*stack_a;
	// t_list *stack_b;
	if (argc == 1 || validate_args(argv, argc) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	values = format_args(argv,&r_count);

	create_stack_a(&stack_a, values, r_count);
	ft_printf("\nstack antes ordenação\n-----------------\n");
	print_stack(stack_a);
	ft_printf("\nINICIANDO OPERAÇÕES\n-------------------\n");
	if (r_count <= 3)
	{
		op_three_vls(&stack_a, r_count);
	}
	ft_printf("\nstack após ordenação\n-----------------\n");
	print_stack(stack_a);


	return (0);
}
