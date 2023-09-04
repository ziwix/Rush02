/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:52:29 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 21:24:00 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_error(char *error)
{
	while (*error)
		write(2, error++, 1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\v'
		|| c == '\t' || c == '\r' || c == '\f');
}

int	ft_is_atoi_char(char c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-');
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (-1);
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
