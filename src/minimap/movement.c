/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/19 16:07:43 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_forward(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle) * info->player->move_speed;

	// Calculate the target position for the minimum distance check
	double target_x = new_x + cos(info->player->rotation_angle) * MIN_DISTANCE_FROM_WALL;
	double target_y = new_y + sin(info->player->rotation_angle) * MIN_DISTANCE_FROM_WALL;

	if (wall_check(info->map_info, floor(target_x / SQUARE_SIZE), floor(target_y / SQUARE_SIZE)) == 0)
	{
		// If there is no wall at the target position, it's safe to move
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
	{
		// There is a wall within the minimum distance, do not move
		return;
	}
}

void move_backward(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x - cos(info->player->rotation_angle) * info->player->move_speed;
	new_y = info->player->y - sin(info->player->rotation_angle) * info->player->move_speed;

	// Calculate the target position for the minimum distance check
	double target_x = new_x - cos(info->player->rotation_angle) * MIN_DISTANCE_FROM_WALL;
	double target_y = new_y - sin(info->player->rotation_angle) * MIN_DISTANCE_FROM_WALL;

	if (wall_check(info->map_info, floor(target_x / SQUARE_SIZE), floor(target_y / SQUARE_SIZE)) == 0)
	{
		// If there is no wall at the target position, it's safe to move
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
	{
		// There is a wall within the minimum distance, do not move
		return;
	}
}

void move_right(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle + M_PI_2) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle + M_PI_2) * info->player->move_speed;

	// Calculate the target position for the minimum distance check
	double target_x = new_x + cos(info->player->rotation_angle + M_PI_2) * MIN_DISTANCE_FROM_WALL;
	double target_y = new_y + sin(info->player->rotation_angle + M_PI_2) * MIN_DISTANCE_FROM_WALL;

	if (wall_check(info->map_info, floor(target_x / SQUARE_SIZE), floor(target_y / SQUARE_SIZE)) == 0)
	{
		// If there is no wall at the target position, it's safe to move
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
	{
		// There is a wall within the minimum distance, do not move
		return;
	}
}

void move_left(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle - M_PI_2) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle - M_PI_2) * info->player->move_speed;

	// Calculate the target position for the minimum distance check
	double target_x = new_x + cos(info->player->rotation_angle - M_PI_2) * MIN_DISTANCE_FROM_WALL;
	double target_y = new_y + sin(info->player->rotation_angle - M_PI_2) * MIN_DISTANCE_FROM_WALL;

	if (wall_check(info->map_info, floor(target_x / SQUARE_SIZE), floor(target_y / SQUARE_SIZE)) == 0)
	{
		// If there is no wall at the target position, it's safe to move
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
	{
		// There is a wall within the minimum distance, do not move
		return;
	}
}
