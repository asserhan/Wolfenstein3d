/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 21:00:44 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	ft_minilibx(t_map *map, t_parse *parse, t_game_data *game)
{
	mlx_t	*mlx;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3d", true);
	if (!mlx)
		return (ft_error("Failed to create mlx\n"));
	game->map = map;
	if (init_game(mlx, game, parse))
		return (1);
	mlx_cursor_hook(mlx, &mousehook, game);
	mlx_loop_hook(mlx, &keyhook, game);
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	mlx_loop(mlx);
	mlx_terminate(mlx);
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

int	main(int argc, char **argv)
{
	t_map		*map;
	t_parse		*parse;
	t_game_data	*game;

	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ft_error("Invalid file\n"), 1);
		parse = ft_calloc(1, sizeof(t_parse));
		map = ft_calloc(1, sizeof(t_map));
		if (!parse || !map)
			return (ft_error("Failed to allocate memory\n"), 1);
		if (ft_init_pars(map, parse, argv))
			return (1);
		game = ft_calloc(1, sizeof(t_game_data));
		if (!game)
			return (ft_error("Failed to allocate memory for game\n"));
		ft_minilibx(map, parse, game);
		free_resources(game);
	}
	else
		ft_error("Invalid number of arguments\n");
	return (EXIT_SUCCESS);
}
