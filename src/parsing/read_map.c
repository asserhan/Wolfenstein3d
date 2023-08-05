/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:36:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/08/05 19:38:24 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(int fd)
{
    char *line;
    char *string; 
    char *tmp;
    char **tab ;                                                                                                                                                                       
  
    // fd = open(file,O_RDONLY);
    // if(fd == -1)
    //     return(NULL);
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
char *get_path(char *line)
{
    char *trim;
    trim = ft_strtrim(line,white_spaces);
    if(!trim)
        return(NULL);
    if(open(trim,O_RDONLY) == -1)
        return(free(trim),NULL);
    else
        return(trim);
}
void get_color(t_parse *parse,char **tab)
{
    char *str;
    str = ft_strdup("");
    int i;
    i = -1;
    while(tab[++i])
    {
        str = ft_strjoin(str,tab[i]);
        str = ft_strjoin(str," ");
    }
    str = ft_strtrim(str,white_spaces);
    if(str[0] == 'F')
        
    
}
void check_textures(t_parse *parse,char *line )
{
    (void )parse;
    
    char **tab;
    line = skip_spaces(line);
    tab = ft_split(line,' ');
    if(!tab)
        return(free(line),ft_error("split\n"));
    if(ft_strcmp(tab[0],"NO") == 0)
        parse->no = get_path(tab[1]);
    else if(ft_strcmp(tab[0],"SO") == 0)
        parse->so = get_path(tab[1]);
    else if(ft_strcmp(tab[0],"WE") == 0)
        parse->we = get_path(tab[1]);
    else if(ft_strcmp(tab[0],"EA") == 0)
        parse->ea = get_path(tab[1]);
    else if(tab[0][0] == 'F' || tab[0][1] == 'C')
        get_color(parse,tab);
        
    
}

void ft_parsing(t_parse *parse,int fd)
{
    char *line;
    while(1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        check_textures(parse,line);
    }
}
char **get_map(t_map *map,int fd)
{
   
    map->map = read_map(fd);
    if(!map->map)
        return(ft_printf("Error invalid Map\n"),free_matrix(map->map),NULL);
    //print_matrix(map->map);
    if(check_char(map))
        return(ft_printf("Error Wrong Caracteres\n"),free_matrix(map->map),NULL);
    if(check_borders(map))
        return(ft_printf("Error Map not surounded by walls \n"),free_matrix(map->map),NULL);
    return(map->map);
}