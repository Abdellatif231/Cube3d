/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:17 by amaaouni          #+#    #+#             */
/*   Updated: 2025/03/27 18:27:19 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

void DDA(t_m *data)
{
	int X0 = data->player.x;
	int Y0 = data->player.y;
	int X1 = X0 + cos(data->player.angle) * 90;
	int Y1 = Y0 + sin(data->player.angle) * 90;

	int dx = X1 - X0;
	int dy = Y1 - Y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = X0;
	float Y = Y0;
	int i = 0; 
	while (i <= steps) 
	{
		ft_put_pixel(data->image, X, Y, 0xFF0000FF);
		X += Xinc;
		Y += Yinc;
		i++;
	}
}

void	shot_rays(t_m *data)
{
	int		num_rays = WIDTH;
    float	fov = M_PI / 3;
    float	start_angle = data->player.direction - (fov / 2);
    float	angle_step = fov / num_rays;
	data->player.angle = start_angle;
	int i = 0;
	while (i <= num_rays)
	{
		DDA(data);
		data->player.angle = start_angle + (i * angle_step);
		i++;
	}

}
