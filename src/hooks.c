/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/16 18:48:19 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int key, t_mlx_info *info)
{
	t_player *player;

	player = info->player;
	if (key == 123)

		info->player->rotation_angle -= info->player->rotation_speed;

	else if (key == 124)

		info->player->rotation_angle += info->player->rotation_speed;

	else if (key == 1)

		move_backward(info);

	else if (key == 13)

		move_forward(info);

	else if (key == 0)

		move_left(info);

	else if (key == 2)

		move_right(info);

	else if (key == 53)

		exit(0);

	info->player->rotation_angle = normalize_angle(info->player->rotation_angle);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	cast_all_rays(info);
	draw_mini_map(info, info->map);
	draw_player(info, info->player);

	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_data.img, 0,
							0);
	return (0);
}
