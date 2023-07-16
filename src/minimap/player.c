/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:56:07 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 10:01:45 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->angle = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = 0;
	player->move_speed = 5;
	player->rotation_speed = 3 * (M_PI / 180);
}

void	draw_player(t_mlx_info *mlx_info, t_player *player)
{
	int *cords;

	cords = (int *)malloc(sizeof(int) * 2);
	cords[0] = player->x;
	cords[1] = player->y;
	draw_circle(mlx_info, cords, 5, BLUE);
}