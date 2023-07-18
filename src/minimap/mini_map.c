/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:00:08 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 16:15:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_mini_map(t_mlx_info *mlx_info, char **map)
{
	int *cords;
	int square_size;

	cords = (int *)malloc(sizeof(int) * 2);
	square_size = SQUARE_SIZE;
	cords[0] = 0;
	while (cords[0] < WINDOW_WIDTH)
	{
		cords[1] = 0;
		while (cords[1] < WINDOW_HEIGHT)
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