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

# include "libft/includes/libft.h"


typedef struct stack_list
{
	int	value;
	int	index;
	struct stack_list *next;

} *t_list;

int *	ft_insert_elements(char	*args[], int size);

# endif
