/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:45:48 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/14 17:48:24 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

void	tex_data_init(t_m *data, t_texdata *tex_data, t_ray ray)
{
	tex_data->y = 0;
	if (ray.is_ver)
	{
		tex_data->x_offset = (int)ray.hit_y % TILE_SIZE;
		if (cos(ray.angle) < 0)
			tex_data->tex = data->texture.west;
		else
			tex_data->tex = data->texture.east;
	}
	else
	{
		tex_data->x_offset = (int)ray.hit_x % TILE_SIZE;
		if (sin(ray.angle) > 0)
			tex_data->tex = data->texture.north;
		else
			tex_data->tex = data->texture.south;
	}
}

void	paint_wall(t_m *data, t_texdata *tex_data, t_ray ray, t_wall wall)
{
	if (tex_data->y < wall.top)
		ft_put_pixel(data->image, ray.index, tex_data->y, CEILING_COLOR);
	else if (tex_data->y >= wall.top && tex_data->y < wall.bottom)
	{
		tex_data->y_offset = (tex_data->y - wall.top)
			* ((float)tex_data->tex->height / wall.height);
		tex_data->pixel = &tex_data->tex->pixels
		[4 * (tex_data->y_offset * tex_data->tex->width
				+ tex_data->x_offset)];
		data->color = (tex_data->pixel[0] << 24)
			| (tex_data->pixel[1] << 16)
			| (tex_data->pixel[2] << 8)
			| tex_data->pixel[3];
		ft_put_pixel(data->image, ray.index, tex_data->y, data->color);
	}
	else
		ft_put_pixel(data->image, ray.index, tex_data->y, FLOOR_COLOR);
}

void	render_walls(t_m *data, t_ray ray)
{
	t_wall		wall;
	t_texdata	tex_data;
	double		proj_plane;

	proj_plane = (WIDTH / 2) / tan(data->player.fov / 2);
	wall.height = (TILE_SIZE / ray.distance) * proj_plane;
	wall.top = (HEIGHT / 2) - (wall.height / 2);
	wall.bottom = (HEIGHT / 2) + (wall.height / 2);
	tex_data_init(data, &tex_data, ray);
	while (tex_data.y < HEIGHT)
	{
		paint_wall(data, &tex_data, ray, wall);
		tex_data.y++;
	}
}
