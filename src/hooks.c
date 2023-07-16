/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:23:13 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 11:29:19 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_mlx_info *info)
{
	if (key == 123)
	{
		info->player->x -= 2;
	}
	else if (key == 124)
	{
		info->player->x += 2;
	}
	else if (key == 125)
	{
		info->player->y += 2;
	}
	else if (key == 126)
	{
		info->player->y -= 2;
	}
	draw_mini_map(info, info->map);
	draw_player(info, info->player);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_data.img, 0,
			0);
	// else if (key == 125)
	// {
	// 	info->move.y -= 10;
	// }
	// else if (key == 126)
	// {
	// 	info->move.y += 10;
	// }
	// else if (key == 53)
	// 	exit(0);
	// if (!ft_strcmp(info->av[1], "julia"))
	// 	julia_start(info);
	// if (!ft_strcmp(info->av[1], "mandelbrot"))
	// 	mandel_start(info);
	return (0);
}