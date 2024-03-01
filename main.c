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

#include "push_swap.h"
#include "libft/includes/libft.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_info		info;
	t_point		a;
	if (argc == 1)
	{
		ft_printf("Error");
		return (0);
	}
	a = &info;
	a->stack = ft_insert_elements(argv, argc);

	a->index = 0;
	a->size = argc - 1;
	ft_printf("%d", a->stack[0]);
	return (0);

}
