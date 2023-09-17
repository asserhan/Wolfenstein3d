/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/17 16:11:22 by hasserao         ###   ########.fr       */
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
	int j;
	i = -1;
	//print_matrix(map->map);
	while (++i < map->rows )
	{
		j = -1;
		
		map->map[i] = ft_strtrim(map->map[i],white_spaces);
		if(map->map[i][0] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			return(1); 
		if(ft_strchr(map->map[i],' ') || ft_strchr(map->map[i],'\t'))
		{
			while(map->map[i][++j])
			{
				if(map->map[i][j] == ' ' || map->map[i][j] == '\t')
				{
					if(i != 0 && map->map[i - 1][j] == '0')
						return(1);
					if(i != map->rows - 1 && map->map[i + 1][j] == '0')
						return(1);
					if(map->map[i][j - 1] == '0' || map->map[i][j + 1] == '0')
						return(1);
				}
			
			}
			
		}
			
	}
	
	
	
	// while(map->map[++i])
	// {

		
	// 	j = -1;
	// 	while(map->map[i][++j])
	// 	{
	// 		if(i == 0 || i == map->rows - 1)
	// 		{
	// 			if(map->map[i][j] == '0')
	// 				return(1);
	// 		}
			
		
	// }
	// }
	return(0);

}
