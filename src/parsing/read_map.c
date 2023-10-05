/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:36:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/10/02 19:40:51 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_duplicate(t_parse *parse)
{
	if (parse->in > 6)
		return (ft_error("in parsing\n"));
	if (parse->map_found == 1 && parse->in < 6)
		return (ft_error("in parsing\n"));
	return (0);
}

int	read_map(t_parse *parse, int fd, t_map *map, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (just_spaces(line))
		{
			free(line);
			continue ;
		}
		parse->valid = 0;
		if (check_textures(parse, line))
			return (free(line), 1);
		if (check_duplicate(parse))
			return (free(line), 1);
		get_first_line(map, line, parse);
		if (map->f_line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (0);
}

int	ft_parsing(t_parse *parse, int fd, t_map *map)
{
	char	*line;

	line = NULL;
	if (read_map(parse, fd, map, line))
		return (1);
	if (!map->f_line)
		return (ft_error("map not found\n"));
	if (find_size(map, fd))
		return (ft_error("invalid map\n"));
	close(fd);
	return (0);
}

char	**check_map(t_map *map, char *line, int fd)
{
	int	i;

	i = -1;
	map->map = ft_calloc(sizeof(char *), map->rows + 1);
	if (!map->map)
		return (ft_error("Error malloc\n"), NULL);
	while (++i < map->rows)
	{
		map->map[i] = ft_calloc(sizeof(char), map->cols + 1);
		ft_memset(map->map[i], ' ', map->cols);
		ft_memcpy(map->map[i], line, ft_strlen(line) - 1);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	free(line);
	close(fd);
	if (is_wall(map->map[0]) || is_wall(map->map[map->rows - 1]))
		return (ft_error("Invalid map\n"), NULL);
	if (check_spaces(map))
		return (ft_error("Invalid map\n"), NULL);
	if (check_borders(map))
		return (ft_error("Invalid map\n"), NULL);
	return (map->map);
}

int	get_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("file not found\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, map->f_line) == 0)
			break ;
		free(line);
	}
	free(map->f_line);
	if (!check_map(map, line, fd))
		return (1);
	return (0);
}
