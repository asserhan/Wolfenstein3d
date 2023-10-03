/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/10/03 17:40:46 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_player(t_map *map, int j, int i)
{
	while (map->map[i][++j])
	{
		if (check_char(map->map[i][j]))
			return (1);
		if (ft_strchr("NSEW", map->map[i][j]))
		{
			map->player_num++;
			if (map->player_vue != '\0')
				return (1);
			map->player_vue = map->map[i][j];
			map->map[i][j] = '0';
			map->player_x = j;
			map->player_y = i;
		}
	}
	return (0);
}

int	check_borders(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < map->rows)
	{
		line = ft_strtrim(map->map[i], WHITE_SPACES);
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		{
			free(line);
			return (1);
		}
		free(line);
		j = -1;
		if (check_player(map, j, i))
			return (1);
	}
	if (map->player_num != 1)
		return (1);
	return (0);
}

int	invalid_spaces(t_map *map, int i, int j)
{
	if (map->map[i][j] == ' ' || map->map[i][j] == '\t')
	{
		if (i != 0 && map->map[i - 1][j] != '1' && map->map[i - 1][j] != ' '
			&& map->map[i - 1][j] != '\n')
			return (1);
		if (i != map->rows - 1 && map->map[i + 1][j] != '1' && map->map[i
			+ 1][j] != ' ' && map->map[i + 1][j] != '\n')
			return (1);
		if (j != 0 && map->map[i][j - 1] != '1' && map->map[i][j - 1] != ' '
			&& map->map[i][j - 1] != '\n')
			return (1);
		if (j != map->cols - 1 && map->map[i][j + 1] != '1' && map->map[i][j
			+ 1] != ' ' && map->map[i][j + 1] != '\n')
			return (1);
	}
	return (0);
}

int	check_spaces(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		if (ft_strchr(map->map[i], ' ') || ft_strchr(map->map[i], '\t'))
		{
			j = -1;
			while (map->map[i][++j])
			{
				if (invalid_spaces(map, i, j))
					return (1);
			}
		}
	}
	return (0);
}
