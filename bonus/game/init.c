/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:53:49 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 20:49:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_player(t_game_data *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_error("Failed to allocate memory for player\n");
		return ;
	}
	game->player->x = game->map->player_x * SQUARE_SIZE + SQUARE_SIZE / 2;
	game->player->y = game->map->player_y * SQUARE_SIZE + SQUARE_SIZE / 2;
	if (game->map->player_vue == 'N')
		game->player->player_vue = 3 * M_PI_2;
	else if (game->map->player_vue == 'S')
		game->player->player_vue = M_PI_2;
	else if (game->map->player_vue == 'E')
		game->player->player_vue = 0;
	else if (game->map->player_vue == 'W')
		game->player->player_vue = M_PI;
}

int	init_game(mlx_t *mlx, t_game_data *game, t_parse *parse)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (ft_error("Failed to create image\n"), 1);
	game->prev_x = -1;
	game->img = img;
	game->mlx = mlx;
	game->parse = parse;
	game->map->textures = malloc(sizeof(mlx_image_t *) * 4);
	if (!game->map->textures)
		return (ft_error("Failed to allocate memory for textures\n"), 1);
	game->map->textures[NORTH] = mlx_load_png(parse->no);
	game->map->textures[SOUTH] = mlx_load_png(parse->so);
	game->map->textures[EAST] = mlx_load_png(parse->ea);
	game->map->textures[WEST] = mlx_load_png(parse->we);
	if (!game->map->textures[NORTH] || !game->map->textures[SOUTH]
		|| !game->map->textures[EAST] || !game->map->textures[WEST])
		return (ft_error("Failed to load textures\n"), 1);
	game->map->floor = parse->f;
	game->map->ceiling = parse->c;
	init_player(game);
	if (!game->player)
		return (1);
	return (0);
}

void	init_file(t_parse *parse, t_map *map)
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
