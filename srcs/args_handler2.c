/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:29:22 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:25 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	next_n(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (ft_strchr("+-0123456789", str[i]) == 0)
		{
			while (ft_has_space(str, i) && (str[i] != '\0'))
				i++;
			if (str[i] != '\0' && !(ft_has_space(str, i)))
				return (i);
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	has_rept_v(int *values, int r_count)
{
	int	i_num;
	int	i_gen;

	i_num = 0;
	i_gen = 0;
	r_count = r_count - 1;
	while (i_gen < r_count)
	{
		while (i_num < r_count)
		{
			i_num++;
			if (values[i_gen] == values[i_num])
				return (1);
		}
		i_gen++;
		i_num = i_gen;
	}
	return (0);
}

int	respect_limits(char *argv[], int argc, int *values, int r_count)
{
	int s_i;
	int nv;
	char *str;

	nv = 0;
	if (!has_zero(values, r_count))
		return (1);
	while(++nv < argc)
	{
		s_i = 0;
		str = argv[nv];
		if (str[0] == '0' && (ft_has_space(str, 1) || str[1] == '\0'))
			return (1);
		while (str[s_i++] != '\0')
		{
			if (str[s_i] == '0')
			{
				if (ft_strchr("-123456789",str[s_i - 1]) == 0
					&& (ft_has_space(str, s_i + 1) || str[s_i + 1] == '\0'))
						return (1);
			}
		}
	}
	return (0);
}

int	has_zero(int *values, int r_count)
{
	int	i;

	i = 0;
	while (i < r_count)
	{
		if (values[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int allowed_cond(char *argv[], int argc, int *values, int r_count)
{
	if (has_rept_v(values, r_count))
		return (0);
	if (!respect_limits(argv, argc, values, r_count))
		return (0);
	return (1);
}
