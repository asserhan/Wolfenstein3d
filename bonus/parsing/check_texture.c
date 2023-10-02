/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:23:28 by hasserao          #+#    #+#             */
/*   Updated: 2023/10/02 19:51:52 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
	free_matrix(rgb);
	return (0);
}

int	join_rgb(char **tab, char ***join, int i)
{
	char	**rgb;
	char	**tmp;
	int		j;

	rgb = ft_split(tab[i], ',');
	if (!rgb)
		return (free_matrix(rgb), free_matrix(*join), ft_error("split\n"));
	if (check_digit(rgb))
		return (free_matrix(rgb), free_matrix(*join), ft_error("in colors\n"));
	j = 0;
	while (rgb[j])
	{
		tmp = *join;
		*join = matrix_push_back(tmp, rgb[j]);
		free(tmp);
		j++;
	}
	free_matrix(rgb);
	return (0);
}

int	get_color(t_parse *parse, char **tab)
{
	char	**join;
	int		i;

	parse->valid = 1;
	tab[matrix_size(tab) - 1][ft_strlen(tab[matrix_size(tab) - 1]) - 1] = '\0';
	join = ft_calloc(1, sizeof(char *));
	i = 1;
	while (tab[i])
	{
		if (join_rgb(tab, &join, i))
			return (1);
		i++;
	}
	if (matrix_size(join) != 3)
	{
		return (free_matrix(join), ft_error("in colors\n"));
	}
	if (floor_ceiling(parse, tab[0][0], join))
		return (1);
	return (0);
}

int	ft_textures(t_parse *parse, char **tab, char *line)
{
	if (ft_strcmp(tab[0], "NO") == 0)
	{
		parse->valid = 1;
		if (north_path(parse, tab, line))
			return (1);
	}
	else if (ft_strcmp(tab[0], "SO") == 0)
	{
		parse->valid = 1;
		if (south_path(parse, tab, line))
			return (1);
	}
	else if (ft_strcmp(tab[0], "WE") == 0)
	{
		parse->valid = 1;
		if (west_path(parse, tab, line))
			return (1);
	}
	else if (ft_strcmp(tab[0], "EA") == 0)
	{
		parse->valid = 1;
		if (east_path(parse, tab, line))
			return (1);
	}
	return (0);
}

int	check_textures(t_parse *parse, char *line)
{
	char	**tab;

	line = skip_spaces(line);
	if (line[0] == '1')
	{
		parse->valid = 1;
		parse->map_found = 1;
	}
	if ((line[0] == 'C' || line[0] == 'F') && valid_comma(line))
		return (ft_error("in colors\n"));
	tab = ft_split(line, ' ');
	if (!tab)
		return (free_matrix(tab), ft_error("in split\n"));
	if (ft_textures(parse, tab, line))
		return (1);
	else if (ft_strcmp(tab[0], "F") == 0 || ft_strcmp(tab[0], "C") == 0)
	{
		if (get_color(parse, tab))
			return (free_matrix(tab), 1);
	}
	else if (parse->valid == 0)
		return (free_matrix(tab), ft_error("in parsing\n"));
	free_matrix(tab);
	return (0);
}
