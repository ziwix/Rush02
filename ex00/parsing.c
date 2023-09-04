/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:50:16 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 22:06:24 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "string.h"

t_uint64	ft_atoi(char *str)
{
	t_uint64	value;
	int			i;

	i = 0;
	value = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		value *= 10;
		value += str[i] - '0';
		i++;
	}
	return (value);
}

int	ft_parse_valid_dict(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] == '\n')
		i++;
	if (!ft_is_valid_dict_line(&buffer[i]))
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] != 0 && buffer[i + 1] != '\n')
		{
			if (!ft_is_valid_dict_line(&buffer[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_parse_dict_init(char *buffer, t_list **head, t_list **cursor, int *i)
{
	while (buffer[*i] == '\n')
		(*i)++;
	*head = ft_parse_dict_line(&buffer[*i]);
	*cursor = *head;
	if (!(*head) || !(*head)->value)
		return (0);
	return (1);
}

t_list	*ft_parse_dict(char *buffer)
{
	t_list	*head;
	t_list	*cursor;
	int		i;

	i = 0;
	if (!ft_parse_dict_init(buffer, &head, &cursor, &i))
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] != 0 && buffer[i + 1] != '\n')
		{
			cursor->next = ft_parse_dict_line(&buffer[i + 1]);
			if (cursor->next == NULL)
			{
				ft_list_deinit(head);
				return (NULL);
			}
			cursor = cursor->next;
		}
		i++;
	}
	return (head);
}

t_list	*ft_parse_dict_line(char *buffer)
{
	int		i;
	int		begin;
	t_list	*node;

	i = 0;
	begin = 0;
	node = (t_list *)malloc(sizeof(t_list));
	node->next = NULL;
	if (!node)
		return (NULL);
	node->key = ft_atoi(buffer);
	while (ft_is_atoi_char(buffer[i]) || buffer[i] == ' ')
		i++;
	i ++;
	while (buffer[i] == ' ')
		i ++;
	begin = i;
	while (buffer[i] != '\n')
		i++;
	i--;
	while (buffer[i] == ' ')
		i--;
	i++;
	node->value = ft_strndup(&buffer[begin], i - begin);
	return (node);
}
