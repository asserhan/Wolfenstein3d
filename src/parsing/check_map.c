/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/24 15:25:02 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file(char *file)
{
	while(*file)
		file++;
	file--;
	if (*file != 'b' || *(file - 1) != 'u' || *(file - 2) != 'c' || *(file - 3) != '.')
		return (1);
	return (0);
}
int	check_char(char c)
{
	if (c != '1' && c != '0' && c != '\t' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ' && c != '\n')
		return (1);
	return (0);
}
void	rows_cols_num(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	while (map->map[map->rows])
	{
		while (map->map[map->rows][map->cols])
			map->cols++;
		map->rows++;
	}
}
int	is_wall(char *line)
{
	while (*line)
	{
		if (*line == '0')
			return (1);
		line++;
	}
	return (0);
}
char	*skip_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}
int	check_borders(t_map *map)
{
	int	i;
	int	j;
	char *line;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		line =ft_strtrim(map->map[i], white_spaces);
		if (line[0] != '1' || line[ft_strlen(line)
			- 1] != '1')
		{
			return (1);
		}
		while (map->map[i][++j])
		{
			if (check_char(map->map[i][j]))
			{
			
				return (1);
			}
			if (ft_strchr("NSEW", map->map[i][j]))
			{
				map->player_num++;
				if (map->player_vue != '\0')
				{
					return (1);
				}
				map->player_vue = map->map[i][j];
				map->player_x = j;
				map->player_y = i;
				
			}
		}
	}
	if (map->player_num != 1)
		return (1);
	return (0);
}
