/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:13:01 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/16 15:15:41 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_pixel(t_mlx_info *info, int x, int y, int color)
{
	int pxl_index;
	int red_color;
	int green_color;

	red_color = 0;
	green_color = 0;
	if (color == RED)
		red_color = 200;
	else if (color == GREEN)
		green_color = 200;
	x *= MAP_SCALE;
	y *= MAP_SCALE;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return;
	pxl_index = (info->img_data.size_line * y) + x * 4;
	info->img_data.addr[pxl_index] = 120;
	info->img_data.addr[pxl_index + 1] = green_color;
	info->img_data.addr[pxl_index + 2] = red_color;
}

void draw_pixel_no_scale(t_mlx_info *info, int x, int y, int color)
{
	int pxl_index;
	int red_color;
	int green_color;

	red_color = 0;
	green_color = 0;
	if (color == RED)
		red_color = 200;
	else if (color == GREEN)
		green_color = 200;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return;
	pxl_index = (info->img_data.size_line * y) + x * 4;
	info->img_data.addr[pxl_index] = 120;
	info->img_data.addr[pxl_index + 1] = green_color;
	info->img_data.addr[pxl_index + 2] = red_color;
}
void draw_pixel_texture(t_mlx_info *info, int x, int y, char *color)
{
	int pxl_index;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return;
	pxl_index = (info->img_data.size_line * y) + x * 4;
	info->img_data.addr[pxl_index] = color[0];
	info->img_data.addr[pxl_index + 1] = color[1];
	info->img_data.addr[pxl_index + 2] = color[2];
}