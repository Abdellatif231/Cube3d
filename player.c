/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:45:34 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 14:45:36 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_init(t_m *data)
{
	t_iter	iter;

	iter.w = get_width(data->map);
	iter.h = get_height(data->map);
	iter.i = 0;
	while (iter.i < iter.h)
	{
		iter.j = 0;
		while (iter.j < iter.w)
		{
			if (data->map[iter.i][iter.j] != '1'
				&& data->map[iter.i][iter.j] != '0')
			{
				data->player.x = iter.j * TILE_SIZE + TILE_SIZE / 2;
				data->player.y = iter.i * TILE_SIZE + TILE_SIZE / 2;
				if (data->map[iter.i][iter.j] == 'N')
					data->player.direction = M_PI_2;
				else if (data->map[iter.i][iter.j] == 'E')
					data->player.direction = 0;
				else if (data->map[iter.i][iter.j] == 'S')
					data->player.direction = (3 * M_PI / 2);
				else if (data->map[iter.i][iter.j] == 'W')
					data->player.direction = M_PI;
				return ;
			}
			iter.j++;
		}
		iter.i++;
	}
}

void	player_new_pos(t_m *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->player.x = data->player.x + cos(data->player.direction)
			* MOV_SPEED;
		data->player.y = data->player.y + sin(data->player.direction)
			* MOV_SPEED;
		update(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player.x = data->player.x - cos(data->player.direction)
			* MOV_SPEED;
		data->player.y = data->player.y - sin(data->player.direction)
			* MOV_SPEED;
		update(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->player.x = data->player.x - cos(data->player.direction + M_PI_2)
			* MOV_SPEED;
		data->player.y = data->player.y - sin(data->player.direction + M_PI_2)
			* MOV_SPEED;
		update(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->player.x = data->player.x + cos(data->player.direction + M_PI_2)
			* MOV_SPEED;
		data->player.y = data->player.y + sin(data->player.direction + M_PI_2)
			* MOV_SPEED;
		update(data);
	}
}

void	update(t_m *data)
{
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	draw_map(data);
}
