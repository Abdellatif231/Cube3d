/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:32:18 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/08 12:42:06 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	check_map_name(char *name)
{
	if (!ft_strnstr(name, ".cub", ft_strlen(name)) || count(name, '.') != 1)
		return (1);
	return (0);
}

void	parse(t_data *data, int ac, char **av)
{
	if (ac != 2)
		error("invalid argument number");
	if (check_map_name(av[1]) == 1)
		error("invalid map name");
	fill_map(data, av[1]);
	parse_map(data);
	//	print_stuff(data);
}
