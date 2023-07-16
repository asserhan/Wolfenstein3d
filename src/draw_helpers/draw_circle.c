/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:00:05 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 10:19:12 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_circle(t_mlx_info *mlx_info, int *pixel_cord, int radius,
		int color)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < radius * 2)
	{
		j = 0;
		while (j < radius * 2)
		{
			x = i - radius;
			y = j - radius;
			if ((x * x) + (y * y) <= (radius * radius))
				draw_pixel(mlx_info, pixel_cord[0] + x, pixel_cord[1] + y,
						color);
			j++;
		}
		i++;
	}
}