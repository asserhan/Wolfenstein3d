/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/21 20:59:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void keyhook(mlx_key_data_t keydata, void *param)
{

    // cast param to game_data
    t_game_data *game = (t_game_data *)param;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        game->player->walk_direction = 1;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        game->player->walk_direction = 0;

    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->player->walk_direction = -1;
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        game->player->walk_direction = 0;

    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        game->player->walk_direction = 2;
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        game->player->walk_direction = 0;

    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->player->walk_direction = -2;
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        game->player->walk_direction = 0;
    draw_mini_map(game);
}
