/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:27:59 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/07 22:24:26 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 32
# define ROTATION_SPEED 0.05
# define MOV_SPEED 2
# define NUM_RAYS WIDTH
# define CEILING_COLOR 0xFF
# define WALL_COLOR 0xC0C0C0FF
# define FLOOR_COLOR 0xFF

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_hit
{
	bool		found_wall;
	double		x;
	double		y;
	double		distance;
}				t_hit;

typedef struct s_player
{
	double		x;
	double		y;
	double		direction;
	double		fov;
}				t_player;

typedef struct s_iter
{
	int			x;
	int			y;
	int			i;
	int			j;
	int			w;
	int			h;
	uint32_t	color;
}				t_iter;

typedef struct s_ray
{
	double		angle;
	double		hit_x;
	double		hit_y;
	double		distance;
	int			index;
}				t_ray;

typedef struct s_m
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	t_player	player;
	uint32_t	color;
}				t_m;

void			DDA(t_m *data);
void			draw_map(void *param);
void			ft_put_pixel(mlx_image_t *image, int x, int y, int color);
void			update(t_m *data);
void			shot_rays(t_m *data);
void			player_init(t_m *data);
void			draw_player(t_m *data);
void			draw_tile(t_iter *iter, t_m *data);
int				get_width(char **map);
int				get_height(char **map);
void			ft_hook(void *param);
bool			player_new_pos(t_m *data);
t_hit			cast_ray(t_m *data, double angle);
t_hit			h_inter(t_m *data, double angle);
t_hit			v_inter(t_m *data, double angle);
void			render_walls(t_m *data, t_ray ray);
bool			in_map(char **map, int y, int x);
int				ft_strlen(char *s);
double			normalize_angle(double angle);
bool			has_wall_at(char **map, double x, double y);
uint32_t		darken_color(uint32_t color, float factor);
double			calc_dis(double p_x, double p_y, double x, double y);

#endif
