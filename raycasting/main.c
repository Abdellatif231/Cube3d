/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:44:42 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/07 22:23:06 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	main(void)
{
	t_m	data;

	data.map = malloc(sizeof(char *) * 16);
	data.map[0] = strdup("1111111111111111111");
	data.map[1] = strdup("1000000000000000001");
	data.map[2] = strdup("1001111111111100001");
	data.map[3] = strdup("10010000000001000011111111111");
	data.map[4] = strdup("10000001110001000000011110001");
	data.map[5] = strdup("10000000010001000000000000001");
	data.map[6] = strdup("10010011010001111100000000001");
	data.map[7] = strdup("10000001010000000100010000001");
	data.map[8] = strdup("11110001011111110100010000001");
	data.map[9] = strdup("10000000000000000000011111111");
	data.map[10] = strdup("10011111111111110100000000001");
	data.map[11] = strdup("10010000000000000001111111001");
	data.map[12] = strdup("10010000000000000000000000011");
	data.map[13] = strdup("100100000S000000000000000001");
	data.map[14] = strdup("1111111111111111111111111111");
	data.map[15] = NULL;
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
