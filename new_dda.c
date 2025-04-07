/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:17 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/06 12:04:24 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool has_wall_at(t_m *data, double x, double y)
{
    int map_x = x / TILE_SIZE;
    int map_y = y / TILE_SIZE;

    if (in_map(data->map, map_y, map_x))
		return (data->map[map_y][map_x] == '1');
	return false;
}

int	abs(int n)
{
	if (n > 0)
		return (n);
	return (n * (-1));
}

void	dda(t_m *data, float hit_x, float hit_y)
{
	float	x;
	float	y;
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	int		i;

	dx = (int)hit_x - (int)data->player.x;
	dy = (int)hit_y - (int)data->player.y;
	steps = sqrt(abs(dx) * abs(dx) + abs(dy) * abs(dy));
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	x = data->player.x;
	y = data->player.y;
	i = 0;
	while (i <= steps)
	{
		if (!has_wall_at(data, x, y))
			ft_put_pixel(data->image, x, y, 0xFF0000FF);
		x += xinc;
		y += yinc;
		i++;
	}
}

void	shot_rays(t_m *data)
{
	t_ray	ray;
	t_hit	hit;
	double	start_angle;
	double	angle_step;
	int		i;

	start_angle = normalize_angle(data->player.direction - (FOV / 2));
	ray.angle = start_angle;
	angle_step = (FOV / NUM_RAYS);
	angle_step = normalize_angle(angle_step);
	i = 0;
	while (i <= NUM_RAYS)
	{
		hit = cast_ray(data, ray.angle);
		ray.hit_x = hit.x;
		ray.hit_y = hit.y;
//		dda(data, ray.hit_x, ray.hit_y);
		hit.distance *= cos(normalize_angle(data->player.direction - ray.angle));
		render_walls(data, i, hit.distance);
		ray.angle = normalize_angle(start_angle + i * angle_step);
		i++;
	}
}

void	render_walls(t_m *data, int index, double distance)
{
	int	wall_height;
	int	wall_top;
	int	wall_bottom;
	int	y;

	wall_height = (TILE_SIZE * PROJ_PLANE) / distance;
	wall_top = (HEIGHT / 2) - (wall_height / 2);
	wall_bottom = (HEIGHT / 2) + (wall_height / 2);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < wall_top)
			ft_put_pixel(data->image, index, y, CEILING_COLOR);
		if (y >= wall_top && y <= wall_bottom)
			ft_put_pixel(data->image, index, y, WALL_COLOR);
		else
			ft_put_pixel(data->image, index, y, FLOOR_COLOR);
		y++;
	}
}
