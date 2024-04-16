/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:42:00 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/14 21:42:01 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_has_space(str, i))
			return (0);
		i++;
	}
	return (1);
}
