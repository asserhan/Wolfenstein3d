/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:11:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/26 11:13:45 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_3d_line(t_mlx_info *mlx_info, int *p_cords, double *ray_cords,
		t_ray *ray)
{
	double	ray_dist;
	double	wall_height;
	double	dist_to_plane;
	double	*ray_start_cords;
	double	*ray_end_cords;
	double	*tmp;

	ray_dist = distance_between_points(p_cords[0], p_cords[1], ray_cords[0],
			ray_cords[1]);
	// to fix fisheye effect
	ray_dist *= cos(ray->ray_angle - mlx_info->player->rotation_angle);
	dist_to_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (SQUARE_SIZE / ray_dist) * dist_to_plane;
	ray_start_cords = (double *)malloc(sizeof(double) * 2);
	ray_start_cords[0] = ray->ray_id;
	ray_start_cords[1] = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	ray_end_cords = (double *)malloc(sizeof(double) * 2);
	ray_end_cords[0] = ray->ray_id;
	ray_end_cords[1] = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	// draw cieling
	tmp = (double *)malloc(sizeof(double) * 2);
	tmp[0] = ray_start_cords[0];
	tmp[1] = 0;
	draw_line_2(mlx_info, ray_start_cords, tmp, GREEN);
	// draw wall
	draw_line_2(mlx_info, ray_start_cords, ray_end_cords, BLUE);
	// draw floor
	tmp[0] = ray_start_cords[0];
	tmp[1] = WINDOW_HEIGHT;
	draw_line_2(mlx_info, ray_end_cords, tmp, RED);
}
