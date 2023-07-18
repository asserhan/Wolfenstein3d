/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:13:01 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 16:25:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_pixel(t_mlx_info *info, int x, int y, int color)
{
	int pxl_index;
	int red_color;
	int green_color;

	red_color = 0;
	green_color = 0;
	if (color == RED)
		red_color = 90;
	else if (color == GREEN)
		green_color = 90;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pxl_index = (info->img_data.size_line * y) + x * 4;
	info->img_data.addr[pxl_index] = 65;
	info->img_data.addr[pxl_index + 1] = green_color;
	info->img_data.addr[pxl_index + 2] = red_color;
}