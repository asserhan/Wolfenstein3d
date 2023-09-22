/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:20 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 19:17:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_wall(int x, int y, t_map *map)
{

    if (x >= 0 && x < map->cols && y >= 0 && y < map->rows)
    {
        if (map->map[y][x] == '1')
            return (1);
    }
    return (0);
}

void draw_player(t_game_data *game)
{
    int x;
    int y;

    x = game->player->x;
    y = game->player->y;
    mlx_draw_square(game->img, x, y, SQUARE_SIZE / 4, 0xFF0000FF);
}
void draw_mini_map(t_game_data *game)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
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
    cast_all_rays(game);
    draw_player(game);
}
