/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/20 14:14:24 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int check_file(char *file)
{
    
    if(ft_strchr(file,'.') == NULL || ft_strcmp(ft_strchr(file,'.'),".cub"))
        return(1);
    return(0);
}
int check_char(char c)
{
	if(c != '1' && c != '0' && c != '\t' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != '\n')
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
int is_wall(char *line)
{

	while(*line)
	{
		if(*line == '0')
			return(1);
		line++;
	}
	return(0);
}
char *skip_spaces(char *line)
{
	
	while(*line == ' ')
		line++;
	return(line);
}
int check_borders(t_map *map)
{
	char *line;	
	int i;
	int j;
	i = -1;
	//print_matrix(map->map);
	while (++i < map->rows  )
	{
		j = -1;
		
		line = ft_strtrim(map->map[i],white_spaces);
		if(line[0] != '1' || line[ft_strlen(line )- 1] != '1')
			return(1); 
			while(map->map[i][++j])
			{
				if(check_char(map->map[i][j]))
					return(1);
				if(ft_strchr("NSEW",map->map[i][j]))
				{
					map->player_num++;
					if(map->player_vue != '\0')
						return(1);
					map->player_vue = map->map[i][j];
					map->map[i][j] = '0';
					map->player_x = j;
					map->player_y = i;
				}
			
			}
			
		}
	if(map->player_num != 1)
		return(1);
	return(0);

}

