/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:58:23 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 16:26:21 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_mlx_info *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	mlx_info->img_data.img = mlx_new_image(mlx_info->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	mlx_info->img_data.addr = mlx_get_data_addr(mlx_info->img_data.img,
												&mlx_info->img_data.bpp,
												&mlx_info->img_data.size_line,
												&mlx_info->img_data.endian);
}