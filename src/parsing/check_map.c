/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:23:15 by hasserao          #+#    #+#             */
/*   Updated: 2023/07/20 18:23:42 by hasserao         ###   ########.fr       */
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
			if(map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'N' && map->map[i][j] != 'W' && map->map[i][j] != 'S' && map->map[i][j] != 'E')
				return(1);
			
			if(map->map[i][j] == 'N' ||  map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
				map->player_num++;
		}
	}
	if(map->player_num != 1)
		return(1);
	return(0);
}
