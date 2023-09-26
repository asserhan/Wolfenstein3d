/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:49:56 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/25 14:05:46 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

int check_obstacles(t_game_data *game, double new_x, double new_y)
{

    double x;
    double y;

    x = new_x - 5;
    while (x <= new_x + 5)
    {
        y = new_y - 5;
        while (y <= new_y + 5)
        {
            if (check_wall((int)floor(x / SQUARE_SIZE), (int)floor(y / SQUARE_SIZE), game->map))
                return (1);
            y += 1.0;
        }
        x += 1.0;
    }
    return (0);
}

void move_forward(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue) * 2.5;
    new_y = game->player->y + sin(game->player->player_vue) * 2.5;

    if (!check_obstacles(game, new_x, new_y))
    {
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void move_backward(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x - cos(game->player->player_vue) * 2.5;
    new_y = game->player->y - sin(game->player->player_vue) * 2.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void move_right(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue + M_PI_2) * 2.5;
    new_y = game->player->y + sin(game->player->player_vue + M_PI_2) * 2.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        game->player->x = new_x;
        game->player->y = new_y;
    }
}
void move_left(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue - M_PI_2) * 2.5;
    new_y = game->player->y + sin(game->player->player_vue - M_PI_2) * 2.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void rotate_right(t_game_data *game)
{
    game->player->player_vue += 0.05;
}

void rotate_left(t_game_data *game)
{
    game->player->player_vue -= 0.05;
}