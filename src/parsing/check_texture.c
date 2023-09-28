/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:23:28 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/28 18:44:44 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	floor_ceiling(t_parse *parse, char c, char **rgb)
{
	if (c == 'F')
	{
		parse->in++;
		parse->f.r = ft_atoi(rgb[0]);
		parse->f.g = ft_atoi(rgb[1]);
		parse->f.b = ft_atoi(rgb[2]);
		if (parse->f.r < 0 || parse->f.r > 255 || parse->f.g < 0
			|| parse->f.g > 255 || parse->f.b < 0 || parse->f.b > 255)
			return (free_matrix(rgb), ft_error("in colors\n"));
	}
	else if (c == 'C')
	{
		parse->in++;
		parse->c.r = ft_atoi(rgb[0]);
		parse->c.g = ft_atoi(rgb[1]);
		parse->c.b = ft_atoi(rgb[2]);
		if (parse->c.r < 0 || parse->c.r > 255 || parse->c.g < 0
			|| parse->c.g > 255 || parse->c.b < 0 || parse->c.b > 255)
			return (free_matrix(rgb), ft_error("in colors\n"));
	}
	return (0);
}

int	get_color(t_parse *parse, char **tab)
{
	char	**rgb;

	rgb = ft_split(tab[1], ',');
	if (!rgb)
		return (free_matrix(rgb), ft_error("split\n"));
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (free_matrix(rgb), ft_error("in colors\n"));
	if (floor_ceiling(parse, tab[0][0], rgb))
		return (1);
	free_matrix(rgb);
	return (0);
}

int	ft_textures(t_parse *parse, char **tab)
{
	if (ft_strcmp(tab[0], "NO") == 0)
	{
		if (north_path(parse, tab))
			return (1);
	}
	else if (ft_strcmp(tab[0], "SO") == 0)
	{
		if (south_path(parse, tab))
			return (1);
	}
	else if (ft_strcmp(tab[0], "WE") == 0)
	{
		if (west_path(parse, tab))
			return (1);
	}
	else if (ft_strcmp(tab[0], "EA") == 0)
	{
		if (east_path(parse, tab))
			return (1);
	}
	return (0);
}

int	check_textures(t_parse *parse, char *line)
{
	char	**tab;

	line = skip_spaces(line);
	if (line[0] == '1')
		parse->map_found = 1;
	tab = ft_split(line, ' ');
	if (!tab)
		return (free_matrix(tab), ft_error("in split\n"));
	if (ft_textures(parse, tab))
		return (1);
	else if (tab[0][0] == 'F' || tab[0][0] == 'C')
	{
		if (get_color(parse, tab))
			return (free_matrix(tab), 1);
	}
	free_matrix(tab);
	return (0);
}
