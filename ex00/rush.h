/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:50:34 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 20:56:07 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "string.h"

typedef unsigned long long	t_uint64;

typedef struct s_dict_node
{
	t_uint64			key;
	char				*value;
	struct s_dict_node	*next;
}	t_list;

// Chained Lists
void		ft_list_deinit(t_list *list);
t_list		*ft_find_key(t_uint64 nb, t_list *start);

// Parsing
t_uint64	ft_atoi(char *str);
t_list		*ft_parse_dict(char *buffer);
t_list		*ft_parse_dict_line(char *buffer);
int			ft_parse_valid_dict(char *buffer);
int			ft_is_valid_dict_line(char *line);

// Digesting
void		ft_put_val(t_list *node);
int			digest_number(t_uint64 nb, t_list *start, t_uint64 *limits);

// File related
int			get_file_size(char *file);
//	read the specified file content to a malloc'd buffer, 
//	return NULL if failed to do so
char		*read_file_content(char *file);
char		*read_from_terminal(int nbytes);

// Common utilities functions
void		ft_print_error(char *error);
int			is_valid_number(char *str);
int			ft_isspace(char c);
int			ft_is_atoi_char(char c);
#endif
