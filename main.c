#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MLX42/MLX42.h"

#define WIDTH 750
#define HEIGHT 500
#define TILE_SIZE 30

typedef struct sok
{
	mlx_image_t* image;
	char **map;
} m_t;

typedef struct s_point
{
	float x;
	float y;
}	t_point;

int get_w(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return i;
}

int get_h(char **map)
{
    int i = 0;
    while (map[0][i])
        i++;
    return i;
}


void ft_randomize(void *param)
{
    m_t *mok = param;
    int w = get_w(mok->map);
    int h = get_h(mok->map);

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            uint32_t color;
            if (mok->map[i][j] == '1')
                color = 0x00;
			else
                color = 0x000000FF;
            for (int x = 0; x < TILE_SIZE; x++)
            {
                for (int y = 0; y < TILE_SIZE; y++)
                {
					mlx_put_pixel(mok->image, (j * TILE_SIZE) + x, (i * TILE_SIZE) + y, color);
                }
            }
        }
    }
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int32_t main(void)
{
	mlx_t* mlx;
	m_t waa3;
	char **map2d;

	map2d = calloc(10, sizeof(char *));
	map2d[0] = strdup("1111111111111111111111111");
	map2d[1] = strdup("1000000000000000000100001");
	map2d[2] = strdup("1001000000000P00000000001");
	map2d[3] = strdup("1001000000000000001000001");
	map2d[4] = strdup("1001000000000000001000001");
	map2d[5] = strdup("1001000000100000001000001");
	map2d[6] = strdup("1001000000000000001000001");
	map2d[7] = strdup("1001000000001000001000001");
	map2d[8] = strdup("1111111111111111111111111");
	map2d[9] = NULL;

	waa3.map = map2d;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(waa3.image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, waa3.image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_randomize, &waa3);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

