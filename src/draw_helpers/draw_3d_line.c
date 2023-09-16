/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:11:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/16 17:30:43 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *get_pixel_color(t_tex_data *tex_data, int x, int y)
{
	char *color;

	int i;

	i = 0;
	color = 0;
	color = &tex_data->addr[(y * tex_data->size_line) + (x * (tex_data->bits_per_pixel / 8))];
	return (color);
}

void draw_north_texture(t_mlx_info *mlx_info, double *line_start_cords, double *line_end_cords)
{
	t_tex_data *tex_data;
	int width;
	int height;
	// Endianness

	tex_data = (t_tex_data *)malloc(sizeof(t_tex_data));
	tex_data->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, "./maps/cat.xpm", &width, &height);
	if (tex_data->img == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	tex_data->addr = mlx_get_data_addr(tex_data->img, &tex_data->bits_per_pixel, &tex_data->size_line, &tex_data->endian);
	// get the color of the pixel at the x,y coordinates
	double tile_x;
	double tex_x;

	tile_x = fmod(line_start_cords[0], SQUARE_SIZE);
	tex_x = (tile_x / SQUARE_SIZE) * width;
	int tex_y = 0;
	double y = line_start_cords[1];
	while (y < line_end_cords[1])
	{
		tex_y = (y - line_start_cords[1]) * (height / (line_end_cords[1] - line_start_cords[1]));
		char *color = get_pixel_color(tex_data, tex_x, tex_y);
		draw_pixel_texture(mlx_info, line_start_cords[0], y, color);
		y++;
	}
}

void draw_horiz_texture(t_ray *ray, t_mlx_info *mlx_info)
{
	double ray_dist;
	double wall_height;
	double dist_to_plane;
	double *ray_start_cords;
	double *ray_end_cords;
	double *tmp;

	ray_dist = distance_between_points(mlx_info->player->x, mlx_info->player->y, ray->wall_hit_x, ray->wall_hit_y);
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
	if (is_face_up(ray->ray_angle))
		// draw_line_2(mlx_info, ray_start_cords, ray_end_cords, BLUE);
		draw_line_2(mlx_info, ray_start_cords, ray_end_cords, BLUE);
	else
		draw_north_texture(mlx_info, ray_start_cords, ray_end_cords);
	// draw_line_2(mlx_info, ray_start_cords, ray_end_cords, BLUE);
	// draw floor
	tmp[0] = ray_start_cords[0];
	tmp[1] = WINDOW_HEIGHT;
	draw_line_2(mlx_info, ray_end_cords, tmp, RED);
}
void draw_vertcl_texture(t_ray *ray, t_mlx_info *mlx_info)
{
	double ray_dist;
	double wall_height;
	double dist_to_plane;
	double *ray_start_cords;
	double *ray_end_cords;
	double *tmp;

	ray_dist = distance_between_points(mlx_info->player->x, mlx_info->player->y, ray->wall_hit_x, ray->wall_hit_y);
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
	if (is_face_right(ray->ray_angle))
		draw_line_2(mlx_info, ray_start_cords, ray_end_cords, BLUE);
	else
		draw_line_2(mlx_info, ray_start_cords, ray_end_cords, RED);
	// draw floor
	tmp[0] = ray_start_cords[0];
	tmp[1] = WINDOW_HEIGHT;
	draw_line_2(mlx_info, ray_end_cords, tmp, RED);
}