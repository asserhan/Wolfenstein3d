/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/27 22:46:58 by otait-ta         ###   ########.fr       */
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
	map->map = NULL;
	map->f_line = NULL;
}
void f()
{
	system("leaks cub3d");
}

void free_resources(t_game_data *game, t_map *map, t_parse *parse)
{
	free_matrix(map->map);
	free(parse->no);
	free(parse->so);
	free(parse->we);
	free(parse->ea);
	free(parse);
	// free(game->player);
	// free(game->map->textures[NORTH]);
	// free(game->map->textures[SOUTH]);
	// free(game->map->textures[EAST]);
	// free(game->map->textures[WEST]);
	// free(game->map->textures);
	free(map);
	// free(game);
}
int main(int argc, char **argv)
{
	t_map *map;
	t_parse *parse;
	t_game_data *game;
	int fd;
	// mlx_t *mlx;
	// int fd;
	atexit(f);
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ft_error("Invalid file\n"), 1);
		if ((fd = open(argv[1], O_DIRECTORY) != -1))
			return (ft_error("Is a directory\n"), 1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("file does not open\n"), 1);
		parse = ft_calloc(1, sizeof(t_parse));
		map = ft_calloc(1, sizeof(t_map));
		if (!parse || !map)
			return (ft_error("Failed to allocate memory\n"), 1);
		init_file(parse, map);
		if (ft_parsing(parse, fd, map))
			exit(1);
		if (!get_map(map, argv[1]))
			exit(1);
		// mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3d", true);
		// if (!mlx)
		// 	ft_error("Failed to create mlx\n");
		// game = ft_calloc(1, sizeof(t_game_data));
		// if (!game)
		// 	ft_error("Failed to allocate memory for game\n");
		// if (init_game(mlx, game, map, parse))
		// 	return (1);
		// mlx_cursor_hook(mlx, &mousehook, game);
		// mlx_loop_hook(mlx, &keyhook, game);
		// mlx_loop(mlx);
		free_resources(game, map, parse);
		// mlx_terminate(mlx);
	}
	else
		ft_error("Invalid number of arguments\n");

	return (EXIT_SUCCESS);
}
