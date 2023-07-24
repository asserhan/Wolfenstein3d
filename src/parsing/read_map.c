/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:36:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/07/24 18:38:16 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(char *file)
{
    char *line;
    char *string; 
    char *tmp;
    char **tab ;                                                                                                                                                                       
    int fd;
    fd = open(file,O_RDONLY);
    if(fd == -1)
        return(NULL);
    string=ft_strdup("");
    while(1)
    {
        line = get_next_line(fd);
        if(ft_strcmp(line,"\n") == 0)
            return(free(line),free(string),NULL);
        if(line == NULL)
            break ;
        tmp = string; 
        string = ft_strjoin(tmp,line);

        free(tmp);
        free(line);
    }
    if(ft_strcmp(string,"") == 0)
    {
        return(free(string),NULL);
    }
    tab = ft_split(string,'\n');
    return(free(string),tab);    

}
char **get_map(t_map *map,char *file)
{
    if(check_file(file))
        return(ft_printf("Error invalid file or does not exist\n"),NULL);
    
    map->map = read_map(file);
    if(!map->map)
        return(ft_printf("Error invalid Map\n"),free_matrix(map->map),NULL);
    print_matrix(map->map);
    if(check_char(map))
        return(ft_printf("Error Wrong Caracteres\n"),free_matrix(map->map),NULL);
    if(check_borders(map))
        return(ft_printf("Error Map not surounded by walls \n"),free_matrix(map->map),NULL);
    return(map->map);
}