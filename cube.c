/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:20:33 by amaaouni          #+#    #+#             */
/*   Updated: 2025/03/27 18:04:06 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return;
	mlx_put_pixel(image, x, y, color);
}

void	player_new_pos(t_m *data)
{
    if (mlx_is_key_down(data->mlx, MLX_KEY_W))
    {
        data->player.x = data->player.x + cos(data->player.direction) * MOV_SPEED;
        data->player.y = data->player.y + sin(data->player.direction) * MOV_SPEED;
		update(data);
    }

	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
    {
        data->player.x = data->player.x - cos(data->player.direction) * MOV_SPEED;
        data->player.y = data->player.y - sin(data->player.direction) * MOV_SPEED;
		update(data);
    }

	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
    {
        data->player.x = data->player.x - cos(data->player.direction + M_PI_2) * MOV_SPEED;
        data->player.y = data->player.y - sin(data->player.direction  + M_PI_2) * MOV_SPEED;
		update(data);
    }

	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
    {
        data->player.x = data->player.x + cos(data->player.direction + M_PI_2) * MOV_SPEED;
        data->player.y = data->player.y + sin(data->player.direction  + M_PI_2) * MOV_SPEED;
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

void ft_hook(void* param)
{
    t_m	*data = param;

    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player.direction -= ROTATION_SPEED;
		update(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
    {
        data->player.direction += ROTATION_SPEED;
        update(data);
    }
	else 
		player_new_pos(data);

	if (data->player.direction < 0)
		data->player.direction += 2 * M_PI;
	else if (data->player.direction > 2 * M_PI)
		data->player.direction -= 2 * M_PI;
}

int get_height(char **map)
{
    int i = 0;
    while (map[i])
        i++;
    return i;
}

int get_width(char **map)
{
    int i = 0;
    while (map[0][i])
        i++;
    return i;
}

void	draw_tile(t_iter *iter, t_m *data)
{
	iter->y = 0;
	while (iter->y < TILE_SIZE)
	{
		iter->x = 0;
		while (iter->x < TILE_SIZE)
		{
			ft_put_pixel(data->image, (iter->j * TILE_SIZE) + iter->x,
					(iter->i * TILE_SIZE) + iter->y, iter->color);
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
			ft_put_pixel(data->image, current_x + iter.j, current_y + iter.i, 0xFF0000FF);
			iter.j++;
		}
		iter.i++;
	}
}

void	player_init(t_m *data)
{
	t_iter  iter;

	iter.w = get_width(data->map);
	iter.h = get_height(data->map);
	iter.i = 0;

	while (iter.i < iter.h)
	{
    	iter.j = 0;
    	while (iter.j < iter.w)
    	{
        	if (data->map[iter.i][iter.j] != '1' && data->map[iter.i][iter.j] != '0')
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
				return;
			}
			iter.j++;
		}
		iter.i++;
	}
}

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

int main(void)
{
	t_m		data;

	data.map = malloc(sizeof(char *) * 10);
						//x x x x x x x x x x x x x x				
	data.map[0] = strdup("1111111111111111111111111");//y
    data.map[1] = strdup("1000000000000000000100001");//y
    data.map[2] = strdup("10011111S0000000000000001");//y
    data.map[3] = strdup("1001000100000000001000001");//y
    data.map[4] = strdup("1001000010000000001000001");//y
    data.map[5] = strdup("1001000000100000001000001");//y
    data.map[6] = strdup("1001000000100000001000001");//y
    data.map[7] = strdup("1001000000001000001000001");//y
    data.map[8] = strdup("1111111111111111111111111");//y
    data.map[9] = NULL;

	data.mlx = mlx_init(WIDTH, HEIGHT, "cube3d", true);
	if (!data.mlx)
		return 1;
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image)
		return 1;
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return 1;

	player_init(&data);
	mlx_loop_hook(data.mlx, draw_map, &data);
	mlx_loop_hook(data.mlx, ft_hook, &data);

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	return 1;
}
