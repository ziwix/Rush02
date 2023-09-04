/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:41:15 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 16:57:39 by maamine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*read_from_terminal(int nbytes)
{
	char	*arg;
	int		size;

	arg = malloc(nbytes * sizeof (char));
	if (!arg)
		return (NULL);
	size = read(0, arg, nbytes);
	if (size <= 1)
		return (NULL);
	arg[size - 1] = '\0';
	return (arg);
}

int	get_file_size(char *dict)
{
	char	buffer[4096];
	int		fd;
	int		tmp;
	int		len;

	fd = open(dict, O_RDONLY);
	if (fd < 1)
		return (-1);
	len = read(fd, buffer, 4096);
	tmp = len;
	while (tmp != 0)
	{
		tmp = read(fd, buffer, 4096);
		len += tmp;
	}
	close(fd);
	return (len);
}

int	file_copy(char *dict, char *dest, int len)
{
	int		fd;

	fd = open(dict, O_RDONLY);
	if (fd < 1)
		return (-1);
	read(fd, dest, len);
	dest[len] = '\0';
	close(fd);
	return (0);
}

char	*read_file_content(char *dict)
{
	int		len;
	char	*str;

	len = get_file_size(dict);
	if (len == -1)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (file_copy(dict, str, len) == -1)
	{
		free(str);
		return (NULL);
	}
	else
		return (str);
}
