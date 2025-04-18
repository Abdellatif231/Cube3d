/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:02:50 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/08 14:03:48 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		printf("%s", map[y]);
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	parse(data, ac, av);
	print_map(data->map);
	raycasting_entry(data);
	free_stuff(data);
}
