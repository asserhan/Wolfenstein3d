/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:41:10 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/28 18:46:11 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_first_line(t_map *map, char *line, t_parse *parse)
{
	if (parse->in == 6)
	{
		if (line[0] == 'C' || line[0] == 'F')
			return ;
		if (just_spaces(line) || line[0] == '\n')
			return ;
		map->f_line = ft_strdup(line);
	}
}

int	read_for_dimensions(t_map *map, char *line, int fd)
{
	int	next_len;
	int	end;

	next_len = 0;
	end = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (just_spaces(line))
		{
			end = 1;
			free(line);
			continue ;
		}
		if (!just_spaces(line) && end == 1)
			return (free(line), 1);
		next_len = ft_strlen(line) - 1;
		if (next_len > map->cols)
			map->cols = next_len;
		map->rows++;
		free(line);
	}
	return (0);
}

int	find_size(t_map *map, int fd)
{
	char	*line;

	line = NULL;
	map->cols = ft_strlen(map->f_line) - 1;
	map->rows = 1;
	if (read_for_dimensions(map, line, fd))
		return (1);
	close(fd);
	return (0);
}
