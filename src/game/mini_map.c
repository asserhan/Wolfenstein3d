/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:20 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/21 20:51:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_player(t_game_data *game)
{
    int x;
    int y;

    x = game->player->x;
    y = game->player->y;
    mlx_draw_square(game->img, x, y, SQUARE_SIZE, 0xFF0000FF);
}
void draw_mini_map(t_game_data *game)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    if (game->player->walk_direction == FORWARD)
    {

        game->player->x += cos(game->player->player_vue) * 5;
        game->player->y += sin(game->player->player_vue) * 5;
    }
    else if (game->player->walk_direction == BACKWARD)
    {

        game->player->x -= cos(game->player->player_vue) * 5;
        game->player->y -= sin(game->player->player_vue) * 5;
    }
    else if (game->player->walk_direction == LEFT)
    {
        game->player->x += cos(game->player->player_vue + M_PI_2) * 5;
        game->player->y += sin(game->player->player_vue + M_PI_2) * 5;
    }
    else if (game->player->walk_direction == RIGHT)
    {
        game->player->x += cos(game->player->player_vue - M_PI_2) * 5;
        game->player->y += sin(game->player->player_vue - M_PI_2) * 5;
    }
    while (i < game->map->rows)
    {
        j = 0;
        while (j < game->map->cols)
        {
            x = j * SQUARE_SIZE;
            y = i * SQUARE_SIZE;
            if (game->map->map[i][j] == '1')
                mlx_draw_square(game->img, x, y, SQUARE_SIZE, 0x0588E1FF);
            else if (game->map->map[i][j] == '0')
                mlx_draw_square(game->img, x, y, SQUARE_SIZE, 0x00FF00FF);
            j++;
        }
        i++;
    }
    draw_player(game);
}
