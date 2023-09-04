/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:40:17 by mrouault          #+#    #+#             */
/*   Updated: 2023/09/03 19:23:54 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h" 

t_list	*get_dict(char *file_name)
{
	char	*file_content;
	t_list	*dict;

	file_content = read_file_content(file_name);
	if (!file_content)
		return (NULL);
	if (!ft_parse_valid_dict(file_content))
		return (NULL);
	dict = ft_parse_dict(file_content);
	free(file_content);
	return (dict);
}

int	check_number(char *str)
{
	int	result;

	result = is_valid_number(str);
	if (result == -1)
	{
		ft_print_error("error\n");
		return (0);
	}
	if (result == 0)
	{
		ft_print_error("Error\n");
		return (0);
	}
	return (1);
}

int	dict_run(char *n, char *dict_file)
{
	t_uint64	*limits;
	t_uint64	number;
	t_list		*head;

	limits = (t_uint64 []){20, 100, 1000, 1000000, 1000000000};
	if (!check_number(n))
		return (1);
	number = ft_atoi(n);
	head = get_dict(dict_file);
	if (!head)
	{
		ft_print_error("Dict Error\n");
		return (1);
	}
	if (number == 0)
		ft_put_val(ft_find_key(number, head));
	else
		digest_number(number, head, limits);
	write(1, "\n", 1);
	ft_list_deinit(head);
	return (0);
}

int	main(int argc, char **argv)
{
	int		exit_code;
	char	*arg;

	if (argc == 2)
		return (dict_run(argv[1], "data/numbers.dict"));
	if (argc == 3)
		return (dict_run(argv[2], argv[1]));
	if (argc == 1)
	{
		arg = read_from_terminal(1024);
		if (!arg)
		{
			ft_print_error("Error\n");
			return (1);
		}
		exit_code = dict_run(arg, "data/numbers.dict");
		free(arg);
		return (exit_code);
	}
	return (0);
}
