/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:36:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/27 23:42:03 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *get_path(char *line)
{
    char *trim;
    trim = ft_strtrim(line, white_spaces);
    if (!trim)
        return (NULL);
    if (access(trim, F_OK | R_OK) == -1)
        return (free(trim), NULL);
    else
        return (trim);
}
int get_color(t_parse *parse, char **tab)
{

    char **rgb;

    rgb = ft_split(tab[1], ',');
    if (!rgb)
        return (free_matrix(rgb), ft_error("split\n"));
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
            return (free_matrix(rgb), ft_error("in colors\n"));
    }
    free_matrix(rgb);
    return (0);
}
int check_textures(t_parse *parse, char *line)
{
    char **tab;

    line = skip_spaces(line);
    if (line[0] == '1')
        parse->map_found = 1;
    tab = ft_split(line, ' ');
    if (!tab)
        return (free_matrix(tab), ft_error("in split\n"));
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
    {
        if (get_color(parse, tab))
            return (free_matrix(tab), 1);
    }
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
            free(line);
            continue;
        }
        if (!just_spaces(line) && end == 1)
            return (free(line), 1);
        next_len = ft_strlen(line) - 1;
        if (next_len > map->cols)
            map->cols = next_len;
        map->rows++;
        free(line);
    }
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
        if (check_textures(parse, line))
            return (free(line), 1);
        if (parse->in > 6)
            return (free(line), ft_error("in parsing\n"));
        if (parse->map_found == 1 && parse->in < 6)
            return (free(line), ft_error("in parsing\n"));

        get_first_line(map, line, parse);
        if (map->f_line)
        {
            free(line);
            line = NULL;
            break;
        }

        free(line);
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
    while (++i < map->rows)
    {
        if (ft_strchr(map->map[i], ' ') || ft_strchr(map->map[i], '\t'))
        {
            j = -1;
            while (map->map[i][++j])
            {
                if (map->map[i][j] == ' ' || map->map[i][j] == '\t')
                {

                    if (i != 0 && map->map[i - 1][j] == '0')
                    {
                        return (1);
                    }
                    if (i != map->rows - 1 && map->map[i + 1][j] == '0')
                    {
                        return (1);
                    }
                    if (j != 0 && map->map[i][j - 1] == '0')
                    {
                        printf("%d %d\n", i, j);
                        return (1);
                    }
                    if (j != map->cols - 1 && map->map[i][j + 1] == '0')
                    {
                        return (1);
                    }
                }
            }
        }
    }
    return (0);
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

        free(line);
    }
    // printf("this is the @ of no : %p *** \n  ", map->f_line);

    free(map->f_line);
    map->map = ft_calloc(sizeof(char *), map->rows + 1);
    if (!map->map)
        return (ft_printf("Error malloc\n"), NULL);
    while (++i < map->rows)
    {
        map->map[i] = ft_calloc(sizeof(char), map->cols + 1);
        ft_memset(map->map[i], ' ', map->cols);
        ft_memcpy(map->map[i], line, ft_strlen(line) - 1);
        free(line);
        line = get_next_line(fd);
        if (line == NULL)
            break;
    }
    free(line);
    close(fd);
    if (is_wall(map->map[0]) || is_wall(map->map[map->rows - 1]))
        return (ft_printf("Invalid // map\n"), NULL);
    if (check_spaces(map))
        return (ft_printf("Invalid ++map\n"), NULL);
    if (check_borders(map))
        return (ft_printf("Invalid **map\n"), NULL);
    return (map->map);
}