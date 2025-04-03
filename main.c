/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:44:42 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 14:45:13 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_m	data;

	data.map = malloc(sizeof(char *) * 10);
	data.map[0] = strdup("1111111111111111111111111");
	data.map[1] = strdup("1000000000000000000100001");
	data.map[2] = strdup("10011111S0000000000000001");
	data.map[3] = strdup("1001000100000000001000001");
	data.map[4] = strdup("1001000010000000001000001");
	data.map[5] = strdup("1001000000100000001000001");
	data.map[6] = strdup("1001000000100000001000001");
	data.map[7] = strdup("1001000000001000001000001");
	data.map[8] = strdup("1111111111111111111111111");
	data.map[9] = NULL;
	data.mlx = mlx_init(WIDTH, HEIGHT, "cube3d", true);
	if (!data.mlx)
		return (1);
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image)
		return (1);
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return (1);
	player_init(&data);
	mlx_loop_hook(data.mlx, draw_map, &data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (1);
}
