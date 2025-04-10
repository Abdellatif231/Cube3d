/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:17 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/08 14:02:16 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	abs(int n)
{
	if (n > 0)
		return (n);
	return (n * (-1));
}

/*
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
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	x = data->player.x;
	y = data->player.y;
	i = 0;
	while (i <= steps)
	{
		ft_put_pixel(data->image, x, y, 0xFF0000FF);
		x += xinc;
		y += yinc;
		i++;
	}
}
*/

uint32_t	darken_color(uint32_t color, float factor)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	r = (uint8_t)(r * factor);
	g = (uint8_t)(g * factor);
	b = (uint8_t)(b * factor);
	return (r << 24 | g << 16 | b << 8 | a);
}

void	shot_rays(t_m *data)
{
	t_ray	ray;
	t_hit	hit;
	float	start_angle;
	float	angle_step;
	double	fov;

	fov = data->player.fov;
	start_angle = normalize_angle(data->player.direction - (fov / 2));
	angle_step = data->player.fov / NUM_RAYS;
	ray.angle = start_angle;
	ray.index = 0;
	while (ray.index < NUM_RAYS)
	{
		ray.angle = normalize_angle(ray.angle);
		hit = cast_ray(data, ray.angle);
		ray.distance = hit.distance * cos(normalize_angle(data->player.direction
					- ray.angle));
		render_walls(data, ray);
		ray.angle += angle_step;
		ray.index++;
	}
}

void	render_walls(t_m *data, t_ray ray)
{
	double	proj_plane;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;
	int		y;

	proj_plane = (WIDTH / 2) / tan(data->player.fov / 2);
	wall_height = (TILE_SIZE / ray.distance) * proj_plane;
	wall_top = (HEIGHT / 2) - (wall_height / 2);
	wall_bottom = (HEIGHT / 2) + (wall_height / 2);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < wall_top)
			ft_put_pixel(data->image, ray.index, y, CEILING_COLOR);
		else if (y >= wall_top && y <= wall_bottom)
			ft_put_pixel(data->image, ray.index, y, data->color);
		else
			ft_put_pixel(data->image, ray.index, y, FLOOR_COLOR);
		y++;
	}
}
