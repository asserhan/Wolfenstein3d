/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/14 15:21:29 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int check_file(char *file)
{
    
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
int is_wall(char c)
{
	return(c == '1');
}
char *skip_spaces(char *line)
{
	
	while(*line == ' ')
		line++;
	return(line);
}
int check_borders(t_map *map)
{
	int i;
	char c;

	i = 0;
	rows_cols_num(map);
	while(i < map->cols)
	{
		c = *skip_spaces(map->map[0]);
		if(!is_wall(c + i))
		{	
			return(1);
		}
		i++;
		printf("%d\n",i);
	}
	return(0);

}
