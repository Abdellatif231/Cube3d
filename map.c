/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:46:25 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 14:47:05 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_map(void *param)
{
	t_m		*data;
	t_iter	iter;

	data = param;
	iter.w = get_width(data->map);
	iter.h = get_height(data->map);
	iter.i = 0;
	while (iter.i < iter.h)
	{
		iter.j = 0;
		while (iter.j < iter.w)
		{
			if (data->map[iter.i][iter.j] == '1')
				iter.color = 0xFFFFFFFF;
			else
				iter.color = 0x00000000;
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
	while (iter->y < TILE_SIZE)
	{
		iter->x = 0;
		while (iter->x < TILE_SIZE)
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

	p_s = TILE_SIZE / 8;
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
}
