/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_free_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:57:35 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 13:39:49 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	value_conditions(char *nptr, int *iter, int *signal, int *v)
{
	int	i;
	int	minus;

	if (ft_strncmp("-2147483648", nptr, ft_strlen(nptr)) == 0)
		*v = -2147483648;
	i = 0;
	minus = 0;
	while (nptr[i] != '\0')
	{
		if (!ft_has_space(nptr, i))
			break ;
		i++;
	}
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		minus = (nptr[i] == 45);
		i++;
	}
	*signal = minus;
	*iter = i;
}

int	verify_max_int(char *nptr, int result, int i)
{
	if (2147483647 - (result * 10) < nptr[i] - 48)
	{
		free (nptr);
		return (0);
	}
	return (1);
}

/*Converts a string into a number, then frees the string pointer
passed as argument*/
int	ft_atoi_free(char *nptr)
{
	int	minus;
	int	i;
	int	result;

	minus = 0;
	result = 0;
	i = 0;
	value_conditions(nptr, &i, &minus, &result);
	if (result == 0)
	{
		while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
		{
			if (verify_max_int(nptr, result, i) == 0)
				return (0);
			result = result * 10 + (nptr[i] - 48);
			i++;
		}
		if (minus != 0)
			result *= -1;
	}
	free(nptr);
	return (result);
}
