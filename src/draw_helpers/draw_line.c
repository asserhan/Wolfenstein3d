/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:30:24 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/21 11:15:42 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

void	draw_line(t_mlx_info *mlx_info, int *start_pixel_cord,
		double *end_pixel_cord, int color)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	delta_x;
	int	delta_y;
	int	step_x;
	int	step_y;
	int	error;
	int	error2;

	x0 = start_pixel_cord[0];
	y0 = start_pixel_cord[1];
	x1 = (int)end_pixel_cord[0];
	y1 = (int)end_pixel_cord[1];
	delta_x = abs(x1 - x0);
	delta_y = abs(y1 - y0);
	step_x = (x0 < x1) ? 1 : -1;
	step_y = (y0 < y1) ? 1 : -1;
	error = delta_x - delta_y;
	while (x0 != x1 || y0 != y1)
	{
		draw_pixel(mlx_info, x0, y0, color);
		error2 = error * 2;
		if (error2 > -delta_y)
		{
			error -= delta_y;
			x0 += step_x;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			y0 += step_y;
		}
	}
	draw_pixel(mlx_info, x0, y0, color); // Draw the last pixel (end point)
}

void	draw_line_2(t_mlx_info *mlx_info, double *start_pixel_cord,
		double *end_pixel_cord, int color)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int delta_x;
	int delta_y;
	int step_x;
	int step_y;
	int error;
	int error2;

	x0 = start_pixel_cord[0];
	y0 = start_pixel_cord[1];
	x1 = (int)end_pixel_cord[0];
	y1 = (int)end_pixel_cord[1];
	delta_x = abs(x1 - x0);
	delta_y = abs(y1 - y0);
	step_x = (x0 < x1) ? 1 : -1;
	step_y = (y0 < y1) ? 1 : -1;
	error = delta_x - delta_y;
	while (x0 != x1 || y0 != y1)
	{
		draw_pixel_no_scale(mlx_info, x0, y0, color);
		error2 = error * 2;
		if (error2 > -delta_y)
		{
			error -= delta_y;
			x0 += step_x;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			y0 += step_y;
		}
	}
	draw_pixel_no_scale(mlx_info, x0, y0, color);
}