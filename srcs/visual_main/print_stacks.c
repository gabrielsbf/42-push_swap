/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:36:17 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 14:36:18 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visual_opt.h"

void	print_stack(t_list **stack, char *text_before)
{
	t_list	*temp_stack;
	int		index;

	ft_printf(text_before);
	temp_stack = (*stack);
	index = 0;
	while (temp_stack->next != NULL && temp_stack)
	{
		ft_printf("index %d valor: %d na posição geral: %d\n",
			index,
			temp_stack->value,
			temp_stack->index);
		temp_stack = temp_stack->next;
		index++;
	}
	if (temp_stack->value)
		ft_printf("index %d valor: %d na posição geral: %d\n",
			index,
			temp_stack->value,
			temp_stack->index);
}
