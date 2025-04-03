/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:20:33 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/03 22:51:34 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_hit find_horizontal_intersection(t_m *data, float angle) {
    t_hit hit;

    hit.found_wall = false;
    hit.distance = 1e9;

    float y_step = (sin(angle) > 0) ? TILE_SIZE : -TILE_SIZE;
    float x_step = y_step / tan(angle);

    float next_y = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
    if (sin(angle) > 0) next_y += TILE_SIZE;
    float next_x = data->player.x + (next_y - data->player.y) / tan(angle);

    while (next_x >= 0 && next_x < WIDTH && next_y >= 0 && next_y < HEIGHT) {
        int map_x = (int)(next_x / TILE_SIZE);
        int map_y = (int)((next_y - (sin(angle) > 0 ? 1 : 0)) / TILE_SIZE);

        if (data->map[map_y][map_x] == '1') {
            hit.found_wall = true;
            hit.x = next_x;
            hit.y = next_y;
            hit.distance = sqrt((hit.x - data->player.x) * (hit.x - data->player.x) +
                                (hit.y - data->player.y) * (hit.y - data->player.y));
            break;
        }
        next_x += x_step;
        next_y += y_step;
    }
    return hit;
}

t_hit find_vertical_intersection(t_m *data, float angle) {
    t_hit hit;
    
    hit.found_wall = false;
    hit.distance = 1e9;
    
    float x_step = (cos(angle) > 0) ? TILE_SIZE : -TILE_SIZE;
    float y_step = x_step * tan(angle);
    
    float next_x = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
    if (cos(angle) > 0) next_x += TILE_SIZE;
    float next_y = data->player.y + (next_x - data->player.x) * tan(angle);
    
    while (next_x >= 0 && next_x < WIDTH && next_y >= 0 && next_y < HEIGHT) {
        int map_x = (int)((next_x - (cos(angle) > 0 ? 1 : 0)) / TILE_SIZE);
        int map_y = (int)(next_y / TILE_SIZE);
        
        if (data->map[map_y][map_x] == '1') {
            hit.found_wall = true;
            hit.x = next_x;
            hit.y = next_y;
            hit.distance = sqrt((hit.x - data->player.x) * (hit.x - data->player.x) + 
                                (hit.y - data->player.y) * (hit.y - data->player.y));
            break;
        }
        next_x += x_step;
        next_y += y_step;
    }
    return hit;
}


