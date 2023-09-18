/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/18 18:24:00 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_forward(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle) * info->player->move_speed;

	if (wall_check(info->map_info, floor(new_x / SQUARE_SIZE), floor(new_y / SQUARE_SIZE)) == 0)
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
		return;
}

void move_backward(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x - cos(info->player->rotation_angle) * info->player->move_speed;
	new_y = info->player->y - sin(info->player->rotation_angle) * info->player->move_speed;
	if (wall_check(info->map_info, floor(new_x / SQUARE_SIZE), floor(new_y / SQUARE_SIZE)) == 0)
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
		return;
}

void move_right(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle + M_PI_2) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle + M_PI_2) * info->player->move_speed;
	if (wall_check(info->map_info, floor(new_x / SQUARE_SIZE), floor(new_y / SQUARE_SIZE)) == 0)
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
		return;
}
void move_left(t_mlx_info *info)
{
	double new_x;
	double new_y;

	new_x = info->player->x + cos(info->player->rotation_angle - M_PI_2) * info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle - M_PI_2) * info->player->move_speed;
	if (wall_check(info->map_info, floor(new_x / SQUARE_SIZE), floor(new_y / SQUARE_SIZE)) == 0)
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
	else
		return;
}
