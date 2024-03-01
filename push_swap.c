/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:16:46 by gabrfern          #+#    #+#             */
/*   Updated: 2024/02/29 16:16:47 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int *	ft_insert_elements(char	*args[], int c_args)
{
	int	*els;
	int	i;
	int	index;

	index = 0;
	i = 1;
	els = (int *)malloc((c_args - 1) * sizeof(int));
	if (!els)
		return 0;
	while(i < c_args)
	{
		els[index] = ft_atoi(args[i]);
		ft_printf("els em index é :%d e atoi do arg é :%d\n",els[index], ft_atoi(args[i]));
		index++;
		i++;
	}
	return (els);
}
