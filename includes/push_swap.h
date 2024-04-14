/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:58 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 13:33:56 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct stack_list
{
	int					value;
	int					index;
	struct stack_list	*next;

}t_list;

int		*format_args(char *argv[], int *r_count);
int		*malloc_from_args(char *argv[], int *r_count);
int		validate_args(char *argv[], int argc);
int		next_n(char *str, int i);
int		is_stack_ordered(t_list **stack_a);
int		elem_in_stack(t_list **stack);
int		has_repeated_v(int *values,int r_count);
void	push_swap(t_list **st_a, t_list **st_b, int count, int *vls);
void	create_stack_a(t_list **stack, int	*s_values, int c_args);
void	create_stack_b(t_list **stack);
int		binary_limit(int r_count);
void	set_stack_indexes(t_list **stack);
int		get_index(t_list **stack, int value);
void	swap_stack(t_list **stack, char stack_name);
void	swap_both_stack(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **from, t_list **to, char stack_to);
void	rotate_stack(t_list **stack, char stack_name);
void	reverse_rotate_stack(t_list **stack, char stack_name);
void	rotate_both_stack(t_list **a, t_list **b);
void	reverse_rotate_both_stack(t_list **a, t_list **b);
void	op_three_vls(t_list **stack_a, int s_count);
void	op_fv_vls(t_list **stack_a, t_list **stack_b);
void	more_than_five(t_list **stack_a, t_list **stack_b, int s_count);
void	order_by_radix(t_list **stack_a, t_list **stack_b, int ind, int count);
void	destroy_stacks(t_list **stack_a, t_list **stack_b);
#endif
