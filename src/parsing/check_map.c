/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/19 13:26:27 by hasserao         ###   ########.fr       */
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
	
	int i;
	int j;
	i = -1;
	//print_matrix(map->map);
	while (++i < map->rows  )
	{
		j = -1;
		
		map->map[i] = ft_strtrim(map->map[i],white_spaces);
		map->map[i + 1] = ft_strtrim(map->map[i + 1],white_spaces);
		
		if(map->map[i][0] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
		{
			return(1); 
		}
		
	
			while(map->map[i][++j])
			{
				if(!ft_strchr("10NSEW \t",map->map[i][j]))
				{
					return(1);
				}
				if(ft_strchr("NSEW",map->map[i][j]))
				{
					map->player_num++;
					printf("player num %d\n",map->player_num);
					if(map->player_vue != '\0')
					{
						return(1);
					}
					map->player_vue = map->map[i][j];
					printf("player vue %c\n",map->player_vue);
					map->player_x = j;
					map->player_y = i;
					printf("player x %d\n",map->player_x);
					printf("player y %d\n",map->player_y);
				}
			
			}
			
		}
			
	
	if(map->player_num != 1)
	{
		printf("here\n");
		return(1);
	}
	
	
	return(0);

}
