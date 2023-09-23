/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/23 10:35:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error(char *str)
{
	ft_printf("Error : ");
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
	t_map *map;
	t_parse *parse;
	t_game_data *game;
	int fd;
	mlx_t *mlx;
	// int fd;
	if (argc == 2)
	{

		if ((fd = open(argv[1], O_DIRECTORY) != -1))
			return (ft_error("Is a directory\n"), 1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("file does not open\n"), 1);
		// TODO: free parse and map
		parse = malloc(sizeof(t_parse));
		map = malloc(sizeof(t_map));
		init_file(parse, map);
		if (ft_parsing(parse, fd, map))
			exit(1);
		get_map(map, argv[1]);
		mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3d", true);
		if (!mlx)
			ft_error("Failed to create mlx\n");
		game = malloc(sizeof(t_game_data));
		if (init_game(mlx, game, map, parse))
			return (1);
		mlx_loop_hook(mlx, &keyhook, game);
		// draw_mini_map(game);
		mlx_loop(mlx);
		// mlx_terminate(mlx);
	}
	else
		ft_error("Invalid number of arguments\n");

	return (EXIT_SUCCESS);
}
