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

int	separate_elements(char *argv[], int argc)
{
	int	i;
	int	nv;

	nv = 1;
	i = 0;
	while(nv < argc)
	{
		while (argv[nv][i]!= '\0')
		{
			if(ft_strchr("0123456789",argv[nv][i]) == 0)
			{
				if((argv[nv][i]>= 7 && argv[nv][i]<= 13) || argv[nv][i] == 32)
					return (i);
			}
			i++;
		}
		nv++;
		i = 0;
	}
}

int	validate_args(char *argv[], int argc)
{
	int	i;
	int	nv;

	nv = 1;
	i = 0;
	while(nv < argc)
	{
		while (argv[nv][i]!= '\0')
		{
			if(ft_strchr("0123456789",argv[nv][i]) == 0)
			{
				if(!(argv[nv][i]>= 7 && argv[nv][i]<= 13) && argv[nv][i] != 32)
					return (0);;
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
	t_list *stack_a;
	// t_list *stack_b;
	if (argc == 1 || validate_args(argv, argc) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("%d\n",separate_elements(argv, argc));
	// create_stack_a(&stack_a, argv, argc);
	// // create_stack_b(&stack_b);

	// reverse_rotate_stack(&stack_a);
	// ft_printf("\nstack a\n");
	// print_stack(stack_a);


	return (0);
}
