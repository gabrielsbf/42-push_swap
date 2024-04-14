/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:37:14 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 14:34:29 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_args(char *argv[], int argc)
{
	int	i;
	int	nv;

	nv = 1;
	i = 0;
	while (nv < argc)
	{
		while (argv[nv][i] != '\0')
		{
			if (ft_strchr("+-", argv[nv][i]) != 0
				&& !ft_isdigit(argv[nv][i + 1]))
				return (0);
			if (ft_strchr("+-0123456789", argv[nv][i]) == 0)
			{
				if (!(ft_has_space(argv[nv], i)) && (argv[nv][i] != '\0'))
					return (0);
			}
			i++;
		}
		nv++;
		i = 0;
	}
	return (1);
}

int	*malloc_from_args(char *argv[], int *r_count)
{
	size_t	i;
	int		nv;
	int		verificator;
	int		*values;

	verificator = *r_count;
	i = 0;
	nv = 1;
	while (nv <= verificator)
	{
		while (i < ft_strlen(argv[nv]))
		{
			i = next_n(argv[nv], i);
			*r_count = *r_count + 1;
		}
		*r_count = *r_count - 1;
		nv++;
		i = 0;
	}
	values = (int *)malloc((*r_count) * sizeof(int));
	if (!values)
		return (NULL);
	return (values);
}

int	invalid_numb_at(char *str)
{
	int	i;

	i = 0;
	ft_printf("entire string is: %s\n", str);
	while (str[i] != '\0')
	{
		ft_printf("Reading char :%c, number %d\n", str[i], str[i]);
		if (ft_strchr("123456789", str[i]) == 0 && !ft_has_space(str, i))
			i++;
		else
			return (0);
	}
	return (1);
}

int	*format_args(char *argv[], int *r_count)
{
	int		s_i;
	int		arg_number;
	int		nv;
	int		*st_values;
	char	*str_sub;

	arg_number = *r_count;
	st_values = malloc_from_args(argv, r_count);
	nv = 1;
	s_i = 0;
	while (nv <= arg_number)
	{
		while (argv[nv][s_i] != '\0')
		{
			str_sub = ft_substr(argv[nv], s_i, next_n(argv[nv], s_i));
			*st_values = ft_atoi_free(str_sub);
			s_i = next_n(argv[nv], s_i);
			st_values++;
		}
		nv++;
		s_i = 0;
	}
	return (st_values - *r_count);
}
