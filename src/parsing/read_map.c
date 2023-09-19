/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:36:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/19 16:30:57 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(int fd)
{
    char *line;
    char *string;
    char *tmp;
    char **tab;

    string = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (ft_strcmp(line, "\n") == 0)
            return (free(line), free(string), NULL);
        if (line == NULL)
            break;
        tmp = string;
        string = ft_strjoin(tmp, line);

        free(tmp);
        free(line);
    }
    if (ft_strcmp(string, "") == 0)
    {
        return (free(string), NULL);
    }
    tab = ft_split(string, '\n');
    return (free(string), tab);
}
char *get_path(char *line)
{
    char *trim;
    char *p;
    trim = ft_strtrim(line, white_spaces);
    if (!trim)
        return (NULL);
    p = trim;
    while (*p)
        p++;
    p--;
    if (*p != 'm' || *(p - 1) != 'p' || *(p - 2) != 'x' || *(p - 3) != '.')
        return (free(trim), NULL);
    // if(ft_strncmp(trim,"./",2) != 0 )
    //     return(free(trim),NULL);
    if (access(trim, F_OK | R_OK) == -1)
        return (free(trim), NULL);
    else
        return (trim);
}
int get_color(t_parse *parse, char **tab)
{

    char **rgb;
    (void)parse;

    rgb = ft_split(tab[1], ',');
    if (!rgb)
        return (ft_error("split\n"));
    if (!rgb[0] || !rgb[1] || !rgb[2])
        return (free_matrix(rgb), ft_error("in colors\n"));
    if (tab[0][0] == 'F')
    {
        parse->in++;
        parse->f.r = ft_atoi(rgb[0]);
        parse->f.g = ft_atoi(rgb[1]);
        parse->f.b = ft_atoi(rgb[2]);
        if (parse->f.r < 0 || parse->f.r > 255 || parse->f.g < 0 || parse->f.g > 255 || parse->f.b < 0 || parse->f.b > 255)
            return (free_matrix(rgb), ft_error("in colors\n"));
    }
    else if (tab[0][0] == 'C')
    {
        parse->in++;
        parse->c.r = ft_atoi(rgb[0]);
        parse->c.g = ft_atoi(rgb[1]);
        parse->c.b = ft_atoi(rgb[2]);
        if (parse->c.r < 0 || parse->c.r > 255 || parse->c.g < 0 || parse->c.g > 255 || parse->c.b < 0 || parse->c.b > 255)
            return (free_matrix(rgb), ft_error("colors\n"));
    }
    free_matrix(rgb);
    return (0);
}
int check_textures(t_parse *parse, char *line)
{
    (void)parse;

    char **tab;
    line = skip_spaces(line);
    if (line[0] == '1')
    {
        parse->map_found = 1;
    }
    tab = ft_split(line, ' ');
    if (!tab)
        return (free(line), ft_error("in split\n"));
    if (ft_strcmp(tab[0], "NO") == 0)
    {
        parse->in++;
        parse->no = get_path(tab[1]);
        if (!parse->no)
            return (free_matrix(tab), ft_error("in textures\n"));
    }
    else if (ft_strcmp(tab[0], "SO") == 0)
    {
        parse->in++;
        parse->so = get_path(tab[1]);
        if (!parse->so)
            return (free_matrix(tab), ft_error("in textures\n"));
    }
    else if (ft_strcmp(tab[0], "WE") == 0)
    {
        parse->in++;
        parse->we = get_path(tab[1]);
        if (!parse->we)
            return (free_matrix(tab), ft_error("in textures\n"));
    }
    else if (ft_strcmp(tab[0], "EA") == 0)
    {
        parse->in++;
        parse->ea = get_path(tab[1]);
        if (!parse->ea)
            return (free_matrix(tab), ft_error("in textures\n"));
    }
    else if (tab[0][0] == 'F' || tab[0][0] == 'C')
        get_color(parse, tab);
    free_matrix(tab);
    return (0);
}

int just_spaces(char *line)
{
    while (*line)
    {
        if (*line != ' ' && *line != '\t' && *line != '\n')
            return (0);
        line++;
    }
    return (1);
}
void get_first_line(t_map *map, char *line, t_parse *parse)
{
   
    if (parse->in == 6)
    {
        if (line[0] == 'C' || line[0] == 'F')
            return;
        if (just_spaces(line) || line[0] == '\n')
            return;
        map->f_line = ft_strdup(line);
    }
}
int find_size(t_map *map, int fd)
{
    char *line;

    
    int next_len;
    int end = 0;
   
    map->cols = ft_strlen(map->f_line) - 1;
    map->rows = 1;
    next_len = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;

        if (just_spaces(line))
        {
            end = 1;
            continue;
        }
        if (!just_spaces(line) && end == 1)
            return (free(line), 1);
        next_len = ft_strlen(line) - 1;
        if (next_len > map->cols)
            map->cols = next_len;
        map->rows++;
    }
    free(line);
    close(fd);
    return (0);
}
int ft_parsing(t_parse *parse, int fd, t_map *map)
{
    char *line;

    while (1)
    {
        line = get_next_line(fd);

        if (line == NULL)
            break;
        if (just_spaces(line))
        {
            free(line);
            continue;
        }
        if (check_textures(parse, line) || parse->in > 6)
            return (free(line), 1);
        if (parse->map_found == 1 && parse->in < 6)
            return (free(line), ft_error("in parsing\n"));

        get_first_line(map, line, parse);
        if (map->f_line)
            break;
    }
    if (!map->f_line)
        return (ft_error("map not found\n"));
    if (find_size(map, fd))
        return (ft_error("invalid map\n"));
    close(fd);
    return (0);
}
int check_spaces(t_map *map)
{
    int i;
    int j;
     i = -1;
    while(++i < map->rows )
    {
       if(ft_strchr(map->map[i],' ') || ft_strchr(map->map[i],'\t'))
        {
            j = -1;
            while(map->map[i][++j])
            {
                if(map->map[i][j] == ' ' || map->map[i][j] == '\t')
				{
                    //printf("%s\n",map->map[i]);
					if(i != 0 && map->map[i - 1][j] == '0')
					{
						return(1);
					}
					if(i != map->rows - 1 && map->map[i + 1][j] == '0')
					{
						printf("%d\n%d\n",i,j);
						return(1);
					}
					if(map->map[i][j - 1] == '0' || map->map[i][j + 1] == '0')
					{
						return(1);
					}
				}
            }
        }
    }
    return(0);
}

char **get_map(t_map *map, char *file)
{
    int fd;
    char *line;

    int i;
    i = -1;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (ft_printf("Error file does not open\n"), NULL);

    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
     
        if (ft_strcmp(line, map->f_line) == 0)
            break;
    }
    map->map = ft_calloc(sizeof(char *), map->rows + 1);
    if (!map->map)
        return (ft_printf("Error malloc\n"), NULL);

    while (++i < map->rows)
    {
        map->map[i] = ft_calloc(sizeof(char), map->cols + 1);
        ft_memset(map->map[i], ' ', map->cols);
        // map->map[i] = ft_strtrim(line,white_spaces);
        ft_memcpy(map->map[i], line, ft_strlen(line));
        line = get_next_line(fd);
        if (line == NULL)
            break;
    }
    //  ft_printf("%s\n",map->map[0]);
    //  ft_printf("%s\n",map->map[map->rows -1]);
   
    if(is_wall(map->map[0]) || is_wall(map->map[map->rows - 1]))
        return(ft_printf("Invalid +++ map\n"),NULL);
    // i = -1;
    // while (map->map[0][++i])
    // {
       
    //     if (map->map[0][i] == '0' )
    //         return (ft_printf("Invalid  map\n"), NULL);
    // }
    // i = -1;
    // while(map->map[map->rows - 1][++i])
    // {
    //     if(map->map[map->rows - 1][i] == '0')
    //         return(ft_printf("Invalid  map\n"),NULL);
    // }
   if(check_spaces(map))
        return(ft_printf("Invalid //map\n"),NULL);
    print_matrix(map->map);
   
    if (check_borders(map))
        return (ft_printf("Invalid ***map\n"), NULL);
    printf("ok\n");
    return (map->map);
}