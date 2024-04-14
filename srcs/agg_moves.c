/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agg_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:02:38 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 16:02:39 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both_stack(t_list **a, t_list **b)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate_both_stack(t_list **a, t_list **b)
{
	reverse_rotate_stack(a, 0);
	reverse_rotate_stack(b, 0);
	ft_printf("rrr\n");
}
