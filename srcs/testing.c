// #include "../includes/push_swap.h"

// void	print_stack(t_list **stack)
// {
// 	t_list *temp_stack;
// 	int	index;

// 	temp_stack = (* stack);
// 	index = 0;
// 	while(temp_stack->next != NULL && temp_stack)
// 	{
// 		ft_printf("index %d valor: %d na posição geral: %d\n", index, temp_stack->value, temp_stack->index);
// 		temp_stack = temp_stack->next;
// 		index++;
// 	}
// 	if(temp_stack->value)
// 		ft_printf("index %d valor: %d na posição geral: %d\n", index, temp_stack->value, temp_stack->index);
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		int value = ft_atoi(argv[1]);
// 		int n = binary_limit(value);
// 		int begin = 0;
// 		while (n > 0)
// 		{
// 			ft_printf("bin is >> %d\n", value >> begin & 1);
// 			begin++;
// 			n--;
// 		}
// 	}
// 	return 0;
// }
