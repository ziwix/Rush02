/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:34:29 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 21:48:54 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	valid_line_number(char *line, int *i)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	if (line[*i] == '+' || line[*i] == '-')
		(*i)++;
	else if (!ft_is_atoi_char(line[*i]))
		return (0);
	while (line[*i] && line[*i] != ':' && line[*i] != '\n')
	{
		if ((line[*i] < '0' || line[*i] > '9') && line[*i] != ' ')
			return (0);
		(*i)++;
	}
	if (line[*i] == ':')
		return (1);
	return (0);
}

int	valid_line_colon_num(char *line)
{
	int	i;
	int	ctr;

	i = 0;
	ctr = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ':')
			ctr++;
		i++;
	}
	return (ctr);
}

int	valid_line_value(char *line, int *i)
{
	while (line[*i] && line[*i] != '\n' && line[*i] == ' ')
		(*i)++;
	if (line[*i] == '\n')
		return (0);
	while (line[*i] && line[*i] != '\n')
	{
		if (line[*i] < ' ' || line[*i] == 127)
			return (0);
		(*i)++;
	}
	return (1);
}

int	ft_is_valid_dict_line(char *line)
{
	int	i;

	i = 0;
	if (!valid_line_number(line, &i))
		return (0);
	if (line[i++] != ':')
		return (0);
	if (!valid_line_value(line, &i))
		return (0);
	return (1);
}
