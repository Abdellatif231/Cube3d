/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:20:33 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/10 14:14:57 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

bool	inter_found(t_m *data, t_hit *hit, t_point next)
{
	if (has_wall_at(data->map, next.x, next.y))
	{
		hit->found_wall = true;
		hit->x = next.x;
		hit->y = next.y;
		hit->distance = calc_dis(data->player.x, data->player.y, hit->x,
				hit->y);
		return (true);
	}
	return (false);
}

void	init_hit(t_hit *hit)
{
	hit->x = 0;
	hit->y = 0;
	hit->distance = 0;
	hit->found_wall = false;
	hit->is_ver = false;
}

t_hit	h_inter(t_m *data, double ray_angle)
{
	t_hit	hit;
	t_point	step;
	t_point	next;

	init_hit(&hit);
	if (sin(ray_angle) > 0)
		step.y = TILE_SIZE;
	else
		step.y = -TILE_SIZE;
	step.x = step.y / tan(ray_angle);
	if (sin(ray_angle) > 0)
		next.y = (floor(data->player.y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
	else
		next.y = (floor(data->player.y / TILE_SIZE) * TILE_SIZE) - 0.001;
	next.x = data->player.x + (next.y - data->player.y) / tan(ray_angle);
	while (in_map(data->map, next.y / TILE_SIZE, next.x / TILE_SIZE))
	{
		if (inter_found(data, &hit, next))
			break ;
		next.x += step.x;
		next.y += step.y;
	}
	return (hit);
}

t_hit	v_inter(t_m *data, double ray_angle)
{
	t_hit	hit;
	t_point	step;
	t_point	next;

	init_hit(&hit);
	if (cos(ray_angle) > 0)
		step.x = TILE_SIZE;
	else
		step.x = -TILE_SIZE;
	step.y = step.x * tan(ray_angle);
	if (cos(ray_angle) > 0)
		next.x = (floor(data->player.x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
	else
		next.x = (floor(data->player.x / TILE_SIZE) * TILE_SIZE) - 0.001;
	next.y = data->player.y + (next.x - data->player.x) * tan(ray_angle);
	while (in_map(data->map, next.y / TILE_SIZE, next.x / TILE_SIZE))
	{
		if (inter_found(data, &hit, next))
			break ;
		next.x += step.x;
		next.y += step.y;
	}
	return (hit);
}

t_hit	cast_ray(t_m *data, double ray_angle)
{
	t_hit	hor_hit;
	t_hit	ver_hit;

	hor_hit = h_inter(data, ray_angle);
	if (!hor_hit.found_wall)
		hor_hit.distance = 800.0;
	ver_hit = v_inter(data, ray_angle);
	if (!ver_hit.found_wall)
		ver_hit.distance = 800.0;
	if (hor_hit.distance < ver_hit.distance)
	{
		hor_hit.is_ver = false;
		data->color = darken_color(WALL_COLOR, 0.9f);
		return (hor_hit);
	}
	data->color = WALL_COLOR;
	ver_hit.is_ver = true;
	return (ver_hit);
}
