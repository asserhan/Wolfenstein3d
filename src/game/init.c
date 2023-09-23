/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:53:49 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/23 11:49:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_player(t_game_data *game)
{
    // TODO: free player
    game->player = malloc(sizeof(t_player));
    game->player->x = game->map->player_x * SQUARE_SIZE + SQUARE_SIZE / 2;
    game->player->y = game->map->player_y * SQUARE_SIZE + SQUARE_SIZE / 2;
    game->player->walk_direction = 0;
    if (game->map->player_vue == 'N')
        game->player->player_vue = 3 * M_PI_2;
    else if (game->map->player_vue == 'S')
        game->player->player_vue = M_PI_2;
    else if (game->map->player_vue == 'E')
        game->player->player_vue = 0;
    else if (game->map->player_vue == 'W')
        game->player->player_vue = M_PI;
}

int init_game(mlx_t *mlx, t_game_data *game, t_map *map, t_parse *parse)
{
    mlx_image_t *img;

    img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
    {
        ft_error("Failed to create image\n");
        return (1);
    }
    game->img = img;
    game->map = map;
    game->mlx = mlx;
    game->map->textures = malloc(sizeof(mlx_image_t *) * 4);
    if (!game->map->textures)
    {
        ft_error("Failed to allocate memory for textures\n");
        return (1);
    }
    game->map->textures[NORTH] = mlx_load_png(parse->no);
    game->map->textures[SOUTH] = mlx_load_png(parse->so);
    game->map->textures[EAST] = mlx_load_png(parse->ea);
    game->map->textures[WEST] = mlx_load_png(parse->we);

    init_player(game);

    return (0);
}
