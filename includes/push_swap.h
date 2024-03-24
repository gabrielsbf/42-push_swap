/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:58 by gabrfern          #+#    #+#             */
/*   Updated: 2024/02/29 16:17:00 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"


typedef struct stack_list
{
	int	value;
	int	index;
	struct stack_list *next;

}t_list;
int		validate_args(char *argv[], int argc);
int		separate_elements(char *argv[], int argc);
void	create_stack_a(t_list **stack, char	*args[], int c_args);
void	create_stack_b(t_list **stack);
void	swap_stack(t_list **stack);
void	swap_both_stack(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **from, t_list **to);
void	rotate_stack(t_list **stack);
void	rotate_both_stack(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_stack(t_list **stack);
void	reverse_rotate_both_stack(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list *stack);
# endif
