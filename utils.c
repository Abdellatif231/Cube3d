/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:47:24 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 14:47:25 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	mlx_put_pixel(image, x, y, color);
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

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
