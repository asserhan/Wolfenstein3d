/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 12:44:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_mlx_info *info)
{
	if (key == 123)
	{
		info->player->rotation_angle -= info->player->rotation_speed;
	}
	else if (key == 124)
	{
		info->player->rotation_angle += info->player->rotation_speed;
	}
	else if (key == 125)
	{
		info->player->y += info->player->move_speed;
	}
	else if (key == 126)
	{
		info->player->y -= info->player->move_speed;
	}
	draw_mini_map(info, info->map);
	draw_player(info, info->player);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_data.img, 0,
			0);
	return (0);
}