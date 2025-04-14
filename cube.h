/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:27:59 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/14 17:13:31 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 400
# define TILE_SIZE 32
# define ROTATION_SPEED 0.05
# define MOV_SPEED 2
# define NUM_RAYS WIDTH
# define CEILING_COLOR 0xFFFFFF
# define WALL_COLOR 0xC0C0C0FF
# define FLOOR_COLOR 0xFFFF00

typedef struct s_data	t_data;

typedef struct s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct s_hit
{
	bool				found_wall;
	double				x;
	double				y;
	double				distance;
	bool				is_ver;
}						t_hit;

typedef struct s_cols
{
	bool				h_free;
	bool				v_free;
	bool				d_free;
	int					map_x;
	int					map_y;
}						t_cols;

typedef struct s_player
{
	double				x;
	double				y;
	double				direction;
	double				fov;
}						t_player;

typedef struct s_iter
{
	int					x;
	int					y;
	int					i;
	int					j;
	int					w;
	int					h;
	uint32_t			color;
}						t_iter;

typedef struct s_ray
{
	double				angle;
	double				hit_x;
	double				hit_y;
	double				distance;
	int					index;
	bool				is_ver;
}						t_ray;

typedef struct s_tex
{
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*east;
	mlx_texture_t		*west;
}						t_tex;

typedef struct s_wall
{
	int					height;
	int					top;
	int					bottom;
}						t_wall;

typedef struct s_texdata
{
	int					x_offset;
	int					y_offset;
	int					y;
	mlx_texture_t		*tex;
	uint8_t				*pixel;
}						t_texdata;

typedef struct s_m
{
	char				**map;
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_tex				texture;
	t_player			player;
	uint32_t			color;
}						t_m;

void					DDA(t_m *data);
void					draw_map(void *param);
void					ft_put_pixel(mlx_image_t *image, int x, int y,
							int color);
void					update(t_m *data);
void					shot_rays(t_m *data);
void					player_init(t_m *data);
void					draw_player(t_m *data);
int						my_strlen(char *s);
void					draw_tile(t_iter *iter, t_m *data);
int						get_width(char **map);
int						get_height(char **map);
void					ft_hook(void *param);
bool					player_new_pos(t_m *data);
t_hit					cast_ray(t_m *data, double angle);
t_hit					h_inter(t_m *data, double angle);
t_hit					v_inter(t_m *data, double angle);
void					render_walls(t_m *data, t_ray ray);
bool					in_map(char **map, int y, int x);
double					normalize_angle(double angle);
bool					has_wall_at(char **map, double x, double y);
uint32_t				darken_color(uint32_t color, float factor);
double					calc_dis(double p_x, double p_y, double x, double y);
int						raycasting_entry(t_data *pars_data);

#endif
