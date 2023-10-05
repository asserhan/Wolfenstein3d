/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:49:56 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/28 21:10:14 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void	move_forward(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x + cos(game->player->player_vue) * 2.5;
	new_y = game->player->y + sin(game->player->player_vue) * 2.5;
	if (!check_obstacles(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_backward(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x - cos(game->player->player_vue) * 2.5;
	new_y = game->player->y - sin(game->player->player_vue) * 2.5;
	if (!check_obstacles(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_right(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x + cos(game->player->player_vue + M_PI_2) * 2.5;
	new_y = game->player->y + sin(game->player->player_vue + M_PI_2) * 2.5;
	if (!check_obstacles(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_left(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x + cos(game->player->player_vue - M_PI_2) * 2.5;
	new_y = game->player->y + sin(game->player->player_vue - M_PI_2) * 2.5;
	if (!check_obstacles(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}
