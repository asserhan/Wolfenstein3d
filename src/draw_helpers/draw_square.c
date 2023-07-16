/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:53:18 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 08:19:29 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_mlx_info *mlx_info, int x_pixel_start, int y_pixel_start,
		int square_size)
{
	int i;
	int j;

	i = 0;

	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			// draw border with black
			if (i == 0 || j == 0 || i == square_size - 1 || j == square_size
				- 1)
				draw_pixel(mlx_info, x_pixel_start + i, y_pixel_start + j,
						BLUE);
			else
				draw_pixel(mlx_info, x_pixel_start + i, y_pixel_start + j,
						GREEN);
			j++;
		}
		i++;
	}
}