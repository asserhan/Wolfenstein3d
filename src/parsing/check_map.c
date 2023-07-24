/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/07/24 16:24:22 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int check_file(char *file)
{
    int fd;
    fd =open (file,O_RDONLY);
    if(fd == -1)
		return(1);
    if(ft_strchr(file,'.') == NULL || ft_strcmp(ft_strchr(file,'.'),".cub"))
        return(1);
    return(0);
}
int check_char(t_map *map)
{
	int i;
	int j;
	i = -1;
	map->player_num = 0;
	while(map->map[++i])
	{
		j = -1;
		while(map->map[i][++j])
		{
			if(map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'N' && map->map[i][j] != 'W' && map->map[i][j] != 'S' && map->map[i][j] != 'E' && map->map[i][j] != ' ')
				return(1);
			
			if(map->map[i][j] == 'N' ||  map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
				map->player_num++;
		}
	}
	if(map->player_num != 1)
		return(1);
	return(0);
}
void rows_cols_num(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	while(map->map[map->rows])
	{
		while(map->map[map->rows][map->cols])
			map->cols++;
		map->rows++;
	}
		
}

int ft_is_wall(char c)
{
	if(c == '1')
		return(1);
	return(0);
}
int ft_is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\v' || c == '\f')
		return(1);
	return(0);
}
char *skip_spaces(char *line)
{

	while(ft_is_space(*line))
		line++;
	return(line);
}
char *trim_spaces(char *line)
{
	int i;
	i = ft_strlen(line) - 1;
	while(ft_is_space(line[i]))
		i--;
	line[i + 1] = '\0';
	return(line);	
}
char *d_space(char *line)
{
	char *str;
	str = skip_spaces(line);
	str = trim_spaces(str);
	return(str);
}


int check_borders(t_map *map)
{
	int i;
	int j;

	 rows_cols_num(map);
	i = 0;
	while(map->map[i] && i >= 0 && i < map->rows)
	{
		d_space(map->map[i]) ;
		j = 0;
		while(map->map[i][j] && j >= 0 && j < map->cols)
		{
	
			if(ft_is_space(map->map[i][j]))
			{
				if((i - 1) >=0 && !ft_is_space(map->map[i - 1][j]) && !ft_is_wall(map->map[i - 1][j]))
					return(1);
				if((i + 1) < map->rows && !ft_is_space(map->map[i + 1][j]) && !ft_is_wall(map->map[i + 1][j]))
					return(1);
				if((j - 1) >= 0 && !ft_is_space(map->map[i][j - 1]) && !ft_is_wall(map->map[i][j - 1]))	
					return(1);
				if((j + 1) < map->cols && !ft_is_space(map->map[i][j + 1]) && !ft_is_wall(map->map[i][j + 1]))	
					return(1);
			}
				j++;
		}
		i++;
	}
	i = 0;
	while(map->map[0][i])
	{
		if(ft_is_wall(*d_space(map->map[0] + i)) ==0)
			return(1);
		i++;
	}
	i = 0;
	while(map->map[map->rows - 1][i])
	{
		if(ft_is_wall(*d_space(map->map[map->rows - 1] + i)) ==0)
			return(1);
		i++;
	}
	i = 0;
	while(map->map[i])
	{
		if(ft_is_wall(*d_space(map->map[i])) ==0)
			return(1);
		i++;
	}
	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
			j++;
		if(ft_is_wall(map->map[i][j - 1]) == 0)
			return(1);
		i++;
	}
	return(0);

}
