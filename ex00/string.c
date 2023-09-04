/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:07:34 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/02 22:45:10 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_strndup(char *src, int n)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(n + 1);
	if (!copy)
		return (NULL);
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
