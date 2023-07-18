/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 16:17:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_mlx_info *info)
{
	double	new_x;
	double	new_y;
	int		map_x;
	int		map_y;

	new_x = info->player->x + cos(info->player->rotation_angle)
		* info->player->move_speed;
	new_y = info->player->y + sin(info->player->rotation_angle)
		* info->player->move_speed;
	map_x = floor(new_x / SQUARE_SIZE);
	map_y = floor(new_y / SQUARE_SIZE);
	if (map_x >= 0 && map_x < GRID_COLS && map_y >= 0 && map_y < GRID_ROWS
		&& info->map[map_y][map_x] != '1')
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
}

void	move_backward(t_mlx_info *info)
{
	double new_x;
	double new_y;
	int map_x;
	int map_y;

	new_x = info->player->x - cos(info->player->rotation_angle)
		* info->player->move_speed;
	new_y = info->player->y - sin(info->player->rotation_angle)
		* info->player->move_speed;
	map_x = floor(new_x / SQUARE_SIZE);
	map_y = floor(new_y / SQUARE_SIZE);
	if (map_x >= 0 && map_x < GRID_COLS && map_y >= 0 && map_y < GRID_ROWS
		&& info->map[map_y][map_x] != '1')
	{
		info->player->x = new_x;
		info->player->y = new_y;
	}
}