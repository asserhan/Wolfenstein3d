/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/21 15:31:18 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error(char *str)
{
	ft_printf("Error\n");
	ft_putstr_fd(str, 2);
	return (1);
}
void init_file(t_parse *parse, t_map *map)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	map->map = malloc(sizeof(char *) * 20000);
	if (!map->map)
	{
		free_matrix(map->map);
		free(map);
	}
	map->player_x = 0;
	map->player_y = 0;
	map->player_vue = '\0';
	map->player_num = 0;
	parse->f.b = -1;
	parse->f.g = -1;
	parse->f.r = -1;
	parse->c.b = -1;
	parse->c.g = -1;
	parse->c.r = -1;
	parse->in = 0;
	parse->map_found = 0;
	map->rows = 0;
	map->cols = 0;
	map->c = 0;
}
int main(int argc, char **argv)
{
	t_map maps;
	t_parse parse;
	int fd;
	// int fd;
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ft_error("Invalid file\n"), 1);
		if ((fd = open(argv[1], O_DIRECTORY) != -1))
			return (ft_error("Is a directory\n"), 1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("file does not open\n"), 1);
		init_file(&parse, &maps);
		if (ft_parsing(&parse, fd, &maps))
			exit(1);
		get_map(&maps, argv[1]);
	}
	else
		ft_error("Invalid number of arguments\n");
	return (0);
}
