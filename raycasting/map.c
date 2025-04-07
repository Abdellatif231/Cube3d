/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:46:25 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/07 22:23:18 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

bool	in_map(char **map, int y, int x)
{
	if (y < 0 || x < 0 || y >= get_height(map) || x >= ft_strlen(map[y]))
		return (false);
	return (true);
}

bool	has_wall_at(char **map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (in_map(map, map_y, map_x))
		return (map[map_y][map_x] == '1');
	return (false);
}

void	update(t_m *data)
{
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	shot_rays(data);
}

/*
void	draw_map(void *param)
{
	t_m		*data;
	t_iter	iter;

	data = param;
	iter.h = get_height(data->map);
	iter.i = 0;
	while (iter.i < iter.h)
	{
		iter.j = 0;
		while (iter.j < ft_strlen(data->map[iter.i]))
		{
			if (data->map[iter.i][iter.j] == '1')
				iter.color = 0xFFFFFFFF;
			else
				iter.color = 0xff;
			draw_tile(&iter, data);
			iter.j++;
		}
		iter.i++;
	}
	draw_player(data);
	shot_rays(data);
}

void	draw_tile(t_iter *iter, t_m *data)
{
	iter->y = 0;
	while (iter->y < TILE_SIZE - 1)
	{
		iter->x = 0;
		while (iter->x < TILE_SIZE - 1)
		{
			ft_put_pixel(data->image, (iter->j * TILE_SIZE) + iter->x, (iter->i
					* TILE_SIZE) + iter->y, iter->color);
			iter->x++;
		}
		iter->y++;
	}
}

void	draw_player(t_m *data)
{
	t_iter	iter;
	int		p_s;
	int		current_x;
	int		current_y;

	p_s = TILE_SIZE / 10;
	current_x = data->player.x;
	current_y = data->player.y;
	iter.i = -p_s;
	while (iter.i <= p_s)
	{
		iter.j = -p_s;
		while (iter.j <= p_s)
		{
			ft_put_pixel(data->image, current_x + iter.j, current_y + iter.i,
				0xFF0000FF);
			iter.j++;
		}
		iter.i++;
	}
}*/
