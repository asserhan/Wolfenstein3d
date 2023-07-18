/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:30:24 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 11:47:32 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_mlx_info *mlx_info, int *start_pixel_cord,
		int *end_pixel_cord, int color)
{
	double delta_x;
	double delta_y;
	int pixels_to_draw;

	delta_x = end_pixel_cord[0] - start_pixel_cord[0];
	delta_y = end_pixel_cord[1] - start_pixel_cord[1];
	pixels_to_draw = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels_to_draw;
	delta_y /= pixels_to_draw;
	while (pixels_to_draw > 0)
	{
		draw_pixel(mlx_info, start_pixel_cord[0], start_pixel_cord[1], color);
		start_pixel_cord[0] += delta_x;
		start_pixel_cord[1] += delta_y;
		pixels_to_draw--;
	}
}