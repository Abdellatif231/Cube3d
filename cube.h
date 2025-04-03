/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:27:59 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 15:55:06 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

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

typedef struct s_ray
{
    float	angle;
    float	hit_x;
    float	hit_y;
    float	distance;
    int		hit_vertical;
}			t_ray;


typedef struct s_m
{
    mlx_t       *mlx;
    mlx_image_t *image;
    char        **map;
	t_player	player;
}               t_m;

void	dda(t_m *data, float hit_x, float hit_y);
void    draw_map(void *param);
void    ft_put_pixel(mlx_image_t *image, int x, int y, int color);
void    update(t_m *data);
void    shot_rays(t_m *data);
void    player_init(t_m *data);
void    draw_player(t_m *data);
void    draw_tile(t_iter *iter, t_m *data);
int		get_width(char **map);
int		get_height(char **map);
void	ft_hook(void* param);
void    player_new_pos(t_m *data);

#endif
