/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:47:24 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/08 14:08:55 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	mlx_put_pixel(image, x, y, color);
}

double	calc_dis(double p_x, double p_y, double x, double y)
{
	return (sqrt((x - p_x) * (x - p_x) + (y - p_y) * (y - p_y)));
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle <= 0)
		angle += 2 * M_PI;
	return (angle);
}
