/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:56:07 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 01:27:52 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 3;
	player->y = WINDOW_HEIGHT / 6;
	player->angle = 30;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = -M_PI_2;
	if (player->rotation_angle >= 0 && player->rotation_angle <= M_PI)
		player->facing_up = 0;
	else
		player->facing_up = 1;
	if (player->rotation_angle >= M_PI_2 && player->rotation_angle <= 3 * M_PI_2)
		player->facing_right = 0;
	else if (player->rotation_angle >= 3 * M_PI_2 && player->rotation_angle <= 2 * M_PI)
		player->facing_right = 1;
	player->move_speed = 12;
	player->rotation_speed = 0.15;
}

void draw_player(t_mlx_info *mlx_info, t_player *player)
{
	int *cords;
	double *end_pixel_cord;

	cords = (int *)malloc(sizeof(int) * 2);
	cords[0] = player->x;
	cords[1] = player->y;
	end_pixel_cord = (double *)malloc(sizeof(double) * 2);
	end_pixel_cord[0] = cords[0] + cos(player->rotation_angle) * 60;
	end_pixel_cord[1] = cords[1] + sin(player->rotation_angle) * 60;
	draw_circle(mlx_info, cords, 5, BLUE);
	draw_line(mlx_info, cords, end_pixel_cord, RED);
	free(cords);
	free(end_pixel_cord);
}