/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:27:59 by amaaouni          #+#    #+#             */
/*   Updated: 2025/03/27 18:04:20 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "MLX42/MLX42.h"

#define WIDTH 750
#define HEIGHT 270
#define TILE_SIZE 30
#define ROTATION_SPEED 0.05
#define	MOV_SPEED 2

typedef struct s_point
{
    float	x;
    float	y;
}			t_point;

typedef struct s_player
{
	float	x;
	float	y;
	double	direction;
	double	angle;
}			t_player;

typedef struct s_iter
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	w;
	int	h;
	int	color;
}	t_iter;

typedef struct s_m
{
    mlx_t       *mlx;
    mlx_image_t *image;
    char        **map;
	t_player	player;
}               t_m;

void DDA(t_m *data);
void    draw_map(void *param);
void    ft_put_pixel(mlx_image_t *image, int x, int y, int color);
void    update(t_m *data);
void    shot_rays(t_m *data);
