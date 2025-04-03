/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:17 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 21:37:15 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	shot_rays(t_m *data)
{
	t_ray	ray;
	int		num_rays;
	float	fov;
	float	start_angle;
	float	angle_step;
	int		i;

	num_rays = WIDTH;
	fov = M_PI / 3;
	start_angle = data->player.direction - (fov / 2);
	angle_step = fov / num_rays;
	ray.angle = start_angle;
	i = 0;
	while (i <= num_rays)
	{
		// get hit_x & hit_y by checking intersections
		// TO DO
		/* 
		  get_hit_point() {
		   check_horizantel();
		   check_vertical();
		   } 
		*/
		ray.hit_x = data->player.x + cos(ray.angle) * 100;
		ray.hit_y = data->player.y + sin(ray.angle) * 100; 
		dda(data, ray.hit_x, ray.hit_y);
		ray.angle += angle_step;
		i++;
	}
}
