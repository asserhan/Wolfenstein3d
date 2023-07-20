/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/20 12:15:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_mlx_info *info)
{
	double	new_x;
	double	new_y;
	double	delta_x;
	double	delta_y;

	delta_x = 0.1;
	delta_y = 0.1;
	while (delta_x < info->player->move_speed
		&& delta_y < info->player->move_speed)
	{
		new_x = info->player->x + cos(info->player->rotation_angle) * delta_x;
		new_y = info->player->y + sin(info->player->rotation_angle) * delta_y;
		if (wall_check(info->map, floor(new_x / SQUARE_SIZE), floor(new_y
					/ SQUARE_SIZE)) == 0)
		{
			delta_x += 0.1;
			delta_y += 0.1;
		}
		else
			return ;
	}
	info->player->x = new_x;
	info->player->y = new_y;
}

void	move_backward(t_mlx_info *info)
{
	double new_x;
	double new_y;
	double delta_x;
	double delta_y;

	delta_x = 0.1;
	delta_y = 0.1;
	while (delta_x < info->player->move_speed
		&& delta_y < info->player->move_speed)
	{
		new_x = info->player->x - cos(info->player->rotation_angle) * delta_x;
		new_y = info->player->y - sin(info->player->rotation_angle) * delta_y;
		if (wall_check(info->map, floor(new_x / SQUARE_SIZE), floor(new_y
					/ SQUARE_SIZE)) == 0)
		{
			delta_x += 0.1;
			delta_y += 0.1;
		}
		else
			return ;
	}
	info->player->x = new_x;
	info->player->y = new_y;
}