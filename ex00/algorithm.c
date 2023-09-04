/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:21:06 by maamine           #+#    #+#             */
/*   Updated: 2023/09/03 19:34:27 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_grammar_specs(t_uint64 nb, t_uint64 *limits, int i)
{
	if (nb % limits[i] < limits[1])
		write(1, " and ", 5);
	else if (i > 1)
		write(1, ", ", 2);
	else
		write(1, " ", 1);
}

int	digest_under_twenty(t_uint64 nb, t_list *start)
{
	t_list	*node;

	node = ft_find_key(nb, start);
	ft_put_val(node);
	return (1);
}

int	digest_under_hundred(t_uint64 nb, t_list *start, t_uint64 *limits)
{
	t_list	*node;

	node = ft_find_key(nb / 10 * 10, start);
	ft_put_val(node);
	if (nb % 10)
	{
		write(1, "-", 1);
		digest_number(nb % 10, start, limits);
	}
	return (1);
}

int	digest_over_hundred(t_uint64 nb, t_list *start,	t_uint64 *limits)
{
	t_list	*node;
	int		i;

	i = 4;
	while (i > 0)
	{
		if (nb >= limits[i])
		{
			digest_number(nb / limits[i], start, limits);
			node = ft_find_key(limits[i], start);
			write(1, " ", 1);
			ft_put_val(node);
			if (nb % limits[i])
			{
				print_grammar_specs(nb, limits, i);
				digest_number(nb % limits[i], start, limits);
			}
			return (1);
		}
		i --;
	}
	return (1);
}

int	digest_number(t_uint64 nb, t_list *start, t_uint64 *limits)
{
	if (nb > 0 && nb < limits[0])
	{
		digest_under_twenty(nb, start);
	}
	else if (nb >= limits[0] && nb < limits[1])
	{
		digest_under_hundred(nb, start, limits);
	}
	else if (nb >= limits[1])
	{
		digest_over_hundred(nb, start, limits);
	}
	return (1);
}
