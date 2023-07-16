/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:00:08 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 09:05:41 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_map(t_mlx_info *mlx_info)
{
	int x;
	int y;
	int square_size;

	if (WINDOW_HEIGHT / GRID_ROWS < WINDOW_WIDTH / GRID_COLS)
		square_size = WINDOW_HEIGHT / GRID_ROWS;
	else
		square_size = WINDOW_WIDTH / GRID_COLS;
	x = 0;
	while (x < WINDOW_WIDTH && x + square_size <= WINDOW_WIDTH && x
		/ square_size < GRID_COLS)
	{
		y = 0;
		while (y < WINDOW_HEIGHT && y + square_size <= WINDOW_HEIGHT && y
			/ square_size < GRID_ROWS)
		{
			draw_square(mlx_info, x, y, square_size);
			y += square_size;
		}
		x += square_size;
	}
}