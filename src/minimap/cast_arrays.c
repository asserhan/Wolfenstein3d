/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:44:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/21 12:06:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	*closet_wall_hit(t_mlx_info *mlx_info, double *tmp, double x_step,
		double y_step, double angle, int type)
{
	double	*first_wall_hit;
	int		*p_cords;
	int		v;
	int		h;

	v = 0;
	h = 0;
	if (type == VERTICAL && !is_face_right(angle))
	{
		v = 1;
		h = 0;
	}
	else if (type == HORIZONTAL && is_face_up(angle))
	{
		v = 0;
		h = 1;
	}
	p_cords = (int *)malloc(sizeof(int) * 2);
	p_cords[0] = mlx_info->player->x;
	p_cords[1] = mlx_info->player->y;
	first_wall_hit = (double *)malloc(sizeof(double) * 2);
	first_wall_hit[0] = tmp[0];
	first_wall_hit[1] = tmp[1];
	while (tmp[0] >= 0 && tmp[0] < WINDOW_WIDTH && tmp[1] >= 0
		&& tmp[1] < WINDOW_HEIGHT)
	{
		if (wall_check(mlx_info->map, floor(tmp[0] / SQUARE_SIZE) - v,
				floor(tmp[1] / SQUARE_SIZE) - h))
		{
			first_wall_hit[0] = tmp[0];
			first_wall_hit[1] = tmp[1];
			return (first_wall_hit);
		}
		tmp[0] += x_step;
		tmp[1] += y_step;
	}
	free(tmp);
	first_wall_hit[0] = -1;
	first_wall_hit[1] = -1;
	return (first_wall_hit);
}

double	*cast_ray_vertically(double ray_angle, t_mlx_info *mlx_info)
{
	double	*tmp;
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;

	tmp = (double *)malloc(sizeof(double) * 2);
	x_intercept = floor(mlx_info->player->x / SQUARE_SIZE) * SQUARE_SIZE;
	if (is_face_right(ray_angle))
		x_intercept += SQUARE_SIZE;
	y_intercept = mlx_info->player->y + ((x_intercept - mlx_info->player->x)
			* tan(ray_angle));
	x_step = SQUARE_SIZE;
	if (!is_face_right(ray_angle))
		x_step *= -1;
	y_step = SQUARE_SIZE * tan(ray_angle);
	if (is_face_up(ray_angle) && y_step > 0)
		y_step *= -1;
	if (!is_face_up(ray_angle) && x_step < 0)
		y_step *= -1;
	tmp[0] = x_intercept;
	tmp[1] = y_intercept;
	return (closet_wall_hit(mlx_info, tmp, x_step, y_step, ray_angle,
			VERTICAL));
}
double	*cast_ray_horizontally(double ray_angle, t_mlx_info *mlx_info)
{
	double	*tmp;
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;

	tmp = (double *)malloc(sizeof(double) * 2);
	y_intercept = floor(mlx_info->player->y / SQUARE_SIZE) * SQUARE_SIZE;
	if (!is_face_up(ray_angle))
		y_intercept += SQUARE_SIZE;
	x_intercept = mlx_info->player->x + ((y_intercept - mlx_info->player->y)
			/ tan(ray_angle));
	y_step = SQUARE_SIZE;
	if (is_face_up(ray_angle))
		y_step *= -1;
	x_step = SQUARE_SIZE / tan(ray_angle);
	if (is_face_right(ray_angle) && x_step < 0)
		x_step *= -1;
	if (!is_face_right(ray_angle) && x_step > 0)
		x_step *= -1;
	tmp[0] = x_intercept;
	tmp[1] = y_intercept;
	return (closet_wall_hit(mlx_info, tmp, x_step, y_step, ray_angle,
			HORIZONTAL));
}

void	cast_ray(double ray_angle, t_mlx_info *mlx_info, int ray_id)
{
	int		*p_cords;
	double	*hor_wall_hit;
	double	*ver_wall_hit;

	p_cords = (int *)malloc(sizeof(int) * 2);
	p_cords[0] = mlx_info->player->x;
	p_cords[1] = mlx_info->player->y;
	hor_wall_hit = cast_ray_horizontally(ray_angle, mlx_info);
	ver_wall_hit = cast_ray_vertically(ray_angle, mlx_info);
	if (hor_wall_hit[0] == -1 && ver_wall_hit[0] != -1)
		draw_3d_line(mlx_info, p_cords, ver_wall_hit, ray_id, ray_angle);
	else if (hor_wall_hit[0] != -1 && ver_wall_hit[0] == -1)
		draw_3d_line(mlx_info, p_cords, hor_wall_hit, ray_id, ray_angle);
	else if (hor_wall_hit[0] != -1 && ver_wall_hit[0] != -1)
	{
		if (distance_between_points(p_cords[0], p_cords[1], hor_wall_hit[0],
				hor_wall_hit[1]) < distance_between_points(p_cords[0],
																														p_cords[1],
																														ver_wall_hit[0],
																														ver_wall_hit[1]))
			draw_3d_line(mlx_info, p_cords, hor_wall_hit, ray_id, ray_angle);
		else
			draw_3d_line(mlx_info, p_cords, ver_wall_hit, ray_id, ray_angle);
	}
}

void	cast_all_rays(t_mlx_info *mlx_info)
{
	int i;
	double ray_angle;
	double delta_angle;

	i = 0;
	delta_angle = FOV_ANGLE / WINDOW_WIDTH;
	ray_angle = mlx_info->player->rotation_angle - (FOV_ANGLE / 2);

	while (i < WINDOW_WIDTH)
	{
		ray_angle = normalize_angle(ray_angle);
		cast_ray(ray_angle, mlx_info, i);
		ray_angle += delta_angle;
		i++;
	}
}