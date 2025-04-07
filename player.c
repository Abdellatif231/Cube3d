/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:45:34 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/07 17:50:30 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_pos(t_m *data, t_iter iter)
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
}

void	player_init(t_m *data)
{
	t_iter	iter;

	iter.h = get_height(data->map);
	iter.i = 0;
	while (iter.i < iter.h)
	{
		iter.j = 0;
		while (iter.j < ft_strlen(data->map[iter.i]))
		{
			if (data->map[iter.i][iter.j] != '1'
				&& data->map[iter.i][iter.j] != '0')
			{
				player_pos(data, iter);
				return ;
			}
			iter.j++;
		}
		iter.i++;
	}
}

bool	key_down(t_m *data, t_point *next)
{
   if (mlx_is_key_down(data->mlx, MLX_KEY_W))
   {
       next->x = data->player.x + cos(data->player.direction) * MOV_SPEED;
       next->y = data->player.y + sin(data->player.direction) * MOV_SPEED;
   }
   else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
   {
       next->x = data->player.x - cos(data->player.direction) * MOV_SPEED;
       next->y = data->player.y - sin(data->player.direction) * MOV_SPEED;
   }
   else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
   {
       next->x = data->player.x - cos(data->player.direction + M_PI_2)
           * MOV_SPEED;
       next->y = data->player.y - sin(data->player.direction + M_PI_2)
           * MOV_SPEED;
   }
   else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
   {
       next->x = data->player.x + cos(data->player.direction + M_PI_2)
           * MOV_SPEED;
       next->y = data->player.y + sin(data->player.direction + M_PI_2)
           * MOV_SPEED;
   }
   else
       return (false);
	return (true);
}

bool	player_new_pos(t_m *data)
{
	t_point	next;
	int		map_x;
	int		map_y;

	next.x = data->player.x;
	next.y = data->player.y;
	if (!key_down(data, &next))
		return (false);
	map_x = next.x / TILE_SIZE;
	map_y = next.y / TILE_SIZE;
	if (!in_map(data->map, map_y, map_x))
		return false;
	if (data->map[map_y][map_x] != '1')
	{
		data->player.x = next.x;
		data->player.y = next.y;
		return (true);
	}
	return (false);
}

void	update(t_m *data)
{
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	shot_rays(data);
//	draw_map(data);
}
