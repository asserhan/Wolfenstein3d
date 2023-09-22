/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:49:56 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 18:01:42 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void move_forward(t_game_data *game)
{
    game->player->x += cos(game->player->player_vue) * 1;
    game->player->y += sin(game->player->player_vue) * 1;
}
void move_backward(t_game_data *game)
{
    game->player->x -= cos(game->player->player_vue) * 1;
    game->player->y -= sin(game->player->player_vue) * 1;
}

void move_right(t_game_data *game)
{
    game->player->x += cos(game->player->player_vue + M_PI_2) * 1;
    game->player->y += sin(game->player->player_vue + M_PI_2) * 1;
}
void move_left(t_game_data *game)
{
    game->player->x += cos(game->player->player_vue - M_PI_2) * 1;
    game->player->y += sin(game->player->player_vue - M_PI_2) * 1;
}

void rotate_right(t_game_data *game)
{
    game->player->player_vue += 0.05;
}

void rotate_left(t_game_data *game)
{
    game->player->player_vue -= 0.05;
}