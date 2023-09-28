/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/28 23:50:11 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *str)
{
	ft_printf("Error : ");
	ft_putstr_fd(str, 2);
	return (1);
}

void	free_resources(t_game_data *game)
{
	free_matrix(game->map->map);
	free(game->map);
	free(game->player);
	free(game->map->textures[NORTH]->pixels);
	free(game->map->textures[NORTH]);
	free(game->map->textures[SOUTH]->pixels);
	free(game->map->textures[SOUTH]);
	free(game->map->textures[EAST]->pixels);
	free(game->map->textures[EAST]);
	free(game->map->textures[WEST]->pixels);
	free(game->map->textures[WEST]);
	free(game->map->textures);
	free(game);
}

int	ft_minilibx(t_map *map, t_parse *parse)
{
	mlx_t		*mlx;
	t_game_data	*game;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3d", true);
	if (!mlx)
		return (ft_error("Failed to create mlx\n"));
	game = ft_calloc(1, sizeof(t_game_data));
	if (!game)
		return (ft_error("Failed to allocate memory for game\n"));
	if (init_game(mlx, game, map, parse))
		return (1);
	mlx_cursor_hook(mlx, &mousehook, game);
	mlx_loop_hook(mlx, &keyhook, game);
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_resources(game);
	return (0);
}

int	ft_init_pars(t_map *map, t_parse *parse, char **argv)
{
	int	fd;

	fd = open(argv[1], O_DIRECTORY);
	if ((fd != -1))
		return (ft_error("Is a directory\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("file does not open\n"), 1);
	init_file(parse, map);
	if (ft_parsing(parse, fd, map))
	{
		close(fd);
		exit(1);
	}
	if (get_map(map, argv[1]))
	{
		close(fd);
		exit(1);
	}
	close(fd);
	return (0);
}
void ff(void)
{
	system("leaks cub3d");
}
int	main(int argc, char **argv)
{
	t_map	*map;
	t_parse	*parse;

	if (argc == 2)
	{
		atexit(ff);
		if (check_file(argv[1]))
			return (ft_error("Invalid file\n"), 1);
		parse = ft_calloc(1, sizeof(t_parse));
		map = ft_calloc(1, sizeof(t_map));
		if (!parse || !map)
			return (ft_error("Failed to allocate memory\n"), 1);
		if (ft_init_pars(map, parse, argv))
			return (1);
		if (ft_minilibx(map, parse))
			return (1);
	}
	else
		ft_error("Invalid number of arguments\n");
	return (EXIT_SUCCESS);
}
