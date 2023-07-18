/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:44:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 20:20:35 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_ray(double ray_angle, t_mlx_info *mlx_info)
{
	double	*end_pixel_cord;
	int		*cords;

	cords = (int *)malloc(sizeof(int) * 2);
	cords[0] = mlx_info->player->x;
	cords[1] = mlx_info->player->y;
	end_pixel_cord = (double *)malloc(sizeof(double) * 2);
	end_pixel_cord[0] = cords[0] + cos(ray_angle) * 60;
	end_pixel_cord[1] = cords[1] + sin(ray_angle) * 60;
	draw_line(mlx_info, cords, end_pixel_cord, BLUE);
	free(end_pixel_cord);
	free(cords);
}

void	cast_all_rays(t_mlx_info *mlx_info)
{
	int i;
	double ray_angle;
	double delta_angle;

	i = 0;
	delta_angle = FOV_ANGLE / WINDOW_WIDTH;
	ray_angle = mlx_info->player->rotation_angle - (FOV_ANGLE / 2);

	while (i < NUM_RAYS)
	{
		cast_ray(ray_angle, mlx_info);
		ray_angle += delta_angle;
		i++;
	}
}