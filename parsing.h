/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:32:37 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/10 11:25:41 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_data
{
	char	**map;
	int		*cieling_color;
	int		*floor_color;
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
}			t_data;

void		parse(t_data *data, int ac, char **av);
void		fill_map(t_data *data, char *name);
void		parse_map(t_data *data);
int			get_map_line_count(char **tmp);
int			count(char *arr, char c);
int			ft_strlen2(char **str);
void		ft_free(char **ptr);
void		free_stuff(t_data *data);
void		error(char *msg);
void		error2(char *str, t_data *data);
void		print_stuff(t_data *data);
char		*ft_strdup_no_newline(const char *src);

#endif
