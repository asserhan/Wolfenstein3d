/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:23:28 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/28 23:46:50 by hasserao         ###   ########.fr       */
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
	free_matrix(rgb);
	return (0);
}
void print_matrix(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		ft_printf("**%s*\n", tab[i]);
		i++;
	}
}


char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	p = dest;
	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}

char	**matrix_push_back(char **matrix, char *back)
{
	char	**new_matrix;
	char	*new_row;
	int		count;
	int		i;

	count = matrix_size(matrix);
	new_matrix = (char **)ft_calloc((count + 1) + 1, sizeof(char *));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (matrix && matrix[i] != NULL)
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		free(matrix[i]);
		i++;
	}
	new_row = (char *)malloc(sizeof(char) * (ft_strlen(back) + 1));
	if (!new_row)
		return (NULL);
	ft_strcpy(new_row, back);
	new_matrix[count] = new_row;
	new_matrix[count + 1] = NULL;
	return (new_matrix);
}

int	get_color(t_parse *parse, char **tab)
{
	(void)parse;
	char	**rgb;
	char **join = ft_calloc(1, sizeof(char *));
	char **tmp;
	
	int i = 1;
	int j = 0;
	while (tab[i])
	{
		rgb = ft_split(tab[i], ',');
		i++;
		if (!rgb)
			return (free_matrix(rgb), ft_error("split\n"));
		
		if(check_digit(rgb))
			return (free_matrix(rgb), ft_error("in b colors\n"));
		j = 0;
		while (rgb[j])
		{
			tmp = join;
			join = matrix_push_back(tmp, rgb[j]);
			free(tmp);
			j++;
		}
	
		free_matrix(rgb);
	}
	if (matrix_size(join) != 3)
			return (free_matrix(join), ft_error("in a1 colors\n"));
	if (floor_ceiling(parse, tab[0][0], join))
			return (1);
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
