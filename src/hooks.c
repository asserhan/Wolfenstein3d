/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/28 00:54:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void keyhook(void *param)
{
    t_game_data *game = (t_game_data *)param;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_forward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_backward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        move_left(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        move_right(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        rotate_left(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        rotate_right(game);
    cast_all_rays(game);
}

void mousehook(double x, double y, void *param)
{

    t_game_data *game;
    int x_diff;
    double sensitivity;

    game = (t_game_data *)param;
    if (x > 0 && x < WINDOW_WIDTH && y > 0 && y < WINDOW_HEIGHT)
    {
        if (game->prev_x != -1)
        {
            x_diff = x - game->prev_x;
            sensitivity = 0.008;
            game->player->player_vue += x_diff * sensitivity;
        }
        game->prev_x = x;
    }
    else
        game->prev_x = -1;
}
