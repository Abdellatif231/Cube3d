/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:45:34 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/14 17:35:10 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

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

	data->player.fov = M_PI / 3;
	iter.h = get_height(data->map);
	iter.i = 0;
	while (iter.i < iter.h)
	{
		iter.j = 0;
		while (iter.j < my_strlen(data->map[iter.i]))
		{
			if (data->map[iter.i][iter.j] != '1'
				&& data->map[iter.i][iter.j] != '0'
				&& data->map[iter.i][iter.j] != '\n')
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
		next->x = cos(data->player.direction);
		next->y = sin(data->player.direction);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		next->x = -cos(data->player.direction);
		next->y = -sin(data->player.direction);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		next->x = -cos(data->player.direction + M_PI_2);
		next->y = -sin(data->player.direction + M_PI_2);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		next->x = cos(data->player.direction + M_PI_2);
		next->y = sin(data->player.direction + M_PI_2);
	}
	else
		return (false);
	return (true);
}

bool	player_new_pos(t_m *data)
{
	t_point	tmp;
	t_point	next;
	t_cols	cols;

	if (!key_down(data, &tmp))
		return (false);
	next.x = data->player.x + tmp.x * MOV_SPEED;
	next.y = data->player.y + tmp.y * MOV_SPEED;
	cols.map_x = (int)(next.x / TILE_SIZE);
	cols.map_y = (int)(next.y / TILE_SIZE);
	cols.h_free = data->map[(int)(data->player.y
			/ TILE_SIZE)][cols.map_x] != '1';
	cols.v_free = data->map[cols.map_y][(int)(data->player.x
			/ TILE_SIZE)] != '1';
	cols.d_free = data->map[cols.map_y][cols.map_x] != '1';
	if (!in_map(data->map, cols.map_y, cols.map_x))
		return (false);
	if (cols.h_free && cols.v_free && cols.d_free)
	{
		data->player.x = next.x;
		data->player.y = next.y;
		return (true);
	}
	return (false);
}

void	ft_hook(void *param)
{
	t_m	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player.direction -= ROTATION_SPEED;
		data->player.direction = normalize_angle(data->player.direction);
		update(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player.direction += ROTATION_SPEED;
		data->player.direction = normalize_angle(data->player.direction);
		update(data);
	}
	else if (player_new_pos(data))
		update(data);
}
