/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:46:50 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/08 11:56:12 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

void	ft_free(char **ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
}

void	free_C_F(t_data *data)
{
	if (data->cieling_color)
	{
		free(data->cieling_color);
		data->cieling_color = NULL;
	}
	if (data->floor_color)
	{
		free(data->floor_color);
		data->floor_color = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
}

void	free_stuff(t_data *data)
{
	if (data->north_text)
	{
		free(data->north_text);
		data->north_text = NULL;
	}
	if (data->south_text)
	{
		free(data->south_text);
		data->south_text = NULL;
	}
	if (data->west_text)
	{
		free(data->west_text);
		data->west_text = NULL;
	}
	if (data->east_text)
	{
		free(data->east_text);
		data->east_text = NULL;
	}
	if (data->map)
		ft_free(data->map);
	free_C_F(data);
}

int	get_map_line_count(char **tmp)
{
	int	i;
	int	map_line_count;

	map_line_count = 0;
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i][0] == '1')
			map_line_count++;
	}
	return (map_line_count);
}
