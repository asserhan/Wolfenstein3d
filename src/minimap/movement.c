/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/12 14:29:09 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_mlx_info *info)
{
	double	new_x;
	double	new_y;
	double	delta_x;
	double	delta_y;

	delta_x = 1;
	delta_y = 1;
	while (delta_x < 50 && delta_y < 50)
	{
		new_x = info->player->x + cos(info->player->rotation_angle) * delta_x;
		new_y = info->player->y + sin(info->player->rotation_angle) * delta_y;
		if (wall_check(info->map, floor(new_x / SQUARE_SIZE), floor(new_y
					/ SQUARE_SIZE)) == 0)
		{
			delta_x += 1;
			delta_y += 1;
		}
		else
			return ;
	}
	info->player->x = info->player->x + cos(info->player->rotation_angle)
		* info->player->move_speed;
	info->player->y = info->player->y + sin(info->player->rotation_angle)
		* info->player->move_speed;
}

void	move_backward(t_mlx_info *info)
{
	double new_x;
	double new_y;
	double delta_x;
	double delta_y;

	delta_x = 1;
	delta_y = 1;
	while (delta_x < 50 && delta_y < 50)
	{
		new_x = info->player->x - cos(info->player->rotation_angle) * delta_x;
		new_y = info->player->y - sin(info->player->rotation_angle) * delta_y;
		if (wall_check(info->map, floor(new_x / SQUARE_SIZE), floor(new_y
					/ SQUARE_SIZE)) == 0)
		{
			delta_x += 1;
			delta_y += 1;
		}
		else
			return ;
	}
	info->player->x = info->player->x - cos(info->player->rotation_angle)
		* info->player->move_speed;
	info->player->y = info->player->y - sin(info->player->rotation_angle)
		* info->player->move_speed;
}