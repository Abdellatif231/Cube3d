/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:44:42 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/08 14:07:09 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	raycasting_entry(t_data *pars_data)
{
	t_m	data;

	data.map = pars_data->map;
	data.mlx = mlx_init(WIDTH, HEIGHT, "cube3d", true);
	if (!data.mlx)
		return (1);
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image)
		return (1);
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return (1);
	player_init(&data);
	shot_rays(&data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (1);
}
