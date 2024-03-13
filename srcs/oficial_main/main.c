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
