/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:12:56 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 16:06:23 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_list_deinit(t_list *list)
{
	if (list == NULL)
		return ;
	if (list->value != NULL)
		free(list->value);
	ft_list_deinit(list->next);
	free(list);
}

t_list	*ft_find_key(t_uint64 nb, t_list *start)
{
	t_list	*node;

	node = start;
	while (node)
	{
		if (node->key == nb)
			return (node);
		node = node->next;
	}
	return (node);
}

void	ft_put_val(t_list *node)
{
	if (node)
		ft_putstr(node->value);
}
