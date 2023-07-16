/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:00:08 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 10:03:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_mini_map(t_mlx_info *mlx_info, char **map)
{
	int *cords;
	int square_size;

	(void)map;
	cords = (int *)malloc(sizeof(int) * 2);
	if (WINDOW_HEIGHT / GRID_ROWS < WINDOW_WIDTH / GRID_COLS)
		square_size = WINDOW_HEIGHT / GRID_ROWS;
	else
		square_size = WINDOW_WIDTH / GRID_COLS;
	cords[0] = 0;
	while (cords[0] < WINDOW_WIDTH && cords[0] + square_size <= WINDOW_WIDTH
		&& cords[0] / square_size < GRID_COLS)
	{
		cords[1] = 0;
		while (cords[1] < WINDOW_HEIGHT && cords[1]
			+ square_size <= WINDOW_HEIGHT && cords[1]
			/ square_size < GRID_ROWS)
		{
			if (map[cords[1] / square_size][cords[0] / square_size] == '1')
				draw_square(mlx_info, cords, square_size, RED);
			else if (map[cords[1] / square_size][cords[0] / square_size] == '0')
				draw_square(mlx_info, cords, square_size, GREEN);
			cords[1] += square_size;
		}
		cords[0] += square_size;
	}
	free(cords);
}