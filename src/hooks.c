/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 18:24:14 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void keyhook(void *param)
{

    // cast param to game_data
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
    draw_mini_map(game);
}
