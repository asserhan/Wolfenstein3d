/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:11:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/16 19:06:57 by otait-ta         ###   ########.fr       */
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

void draw_line_texture(t_mlx_info *mlx_info, t_ray *ray, t_line *line, char *tex_path)
{
	t_tex_data *tex_data;
	int width;
	int height;
	// Endianness

	tex_data = (t_tex_data *)malloc(sizeof(t_tex_data));
	tex_data->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, tex_path, &width, &height);
	if (tex_data->img == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	tex_data->addr = mlx_get_data_addr(tex_data->img, &tex_data->bits_per_pixel, &tex_data->size_line, &tex_data->endian);
	// get the color of the pixel at the x,y coordinates
	double tile_x;
	double tex_x;

	tile_x = fmod(ray->wall_hit_x, SQUARE_SIZE);
	tex_x = (tile_x / SQUARE_SIZE) * width;
	int tex_y = 0;
	double y = line->start_y;
	while (y < line->end_y)
	{
		tex_y = (y - line->start_y) * (height / (line->end_y - line->start_y));
		char *color = get_pixel_color(tex_data, tex_x, tex_y);
		draw_pixel_texture(mlx_info, line->start_x, y, color);
		y++;
	}
}
void draw_vert_line_texture(t_mlx_info *mlx_info, t_ray *ray, t_line *line, char *tex_path)
{
	t_tex_data *tex_data;
	int width;
	int height;
	// Endianness

	tex_data = (t_tex_data *)malloc(sizeof(t_tex_data));
	tex_data->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, tex_path, &width, &height);
	if (tex_data->img == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	tex_data->addr = mlx_get_data_addr(tex_data->img, &tex_data->bits_per_pixel, &tex_data->size_line, &tex_data->endian);
	// get the color of the pixel at the x,y coordinates
	double tile_y;
	double tex_x;

	tile_y = fmod(ray->wall_hit_y, SQUARE_SIZE);
	tex_x = (tile_y / SQUARE_SIZE) * width;
	int tex_y = 0;
	double y = line->start_y;
	while (y < line->end_y)
	{
		tex_y = (y - line->start_y) * (height / (line->end_y - line->start_y));
		char *color = get_pixel_color(tex_data, tex_x, tex_y);
		draw_pixel_texture(mlx_info, line->start_x, y, color);
		y++;
	}
}

void draw_texture(t_ray *ray, t_mlx_info *mlx_info, int type)
{
	double ray_dist;
	double wall_height;
	double dist_to_plane;

	t_line *line;
	t_line *cl_fr_line;

	line = (t_line *)malloc(sizeof(t_line));
	cl_fr_line = (t_line *)malloc(sizeof(t_line));

	ray_dist = distance_between_points(mlx_info->player->x, mlx_info->player->y, ray->wall_hit_x, ray->wall_hit_y);
	// to fix fisheye effect
	ray_dist *= cos(ray->ray_angle - mlx_info->player->rotation_angle);
	dist_to_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (SQUARE_SIZE / ray_dist) * dist_to_plane;
	line->start_x = ray->ray_id;
	line->start_y = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	line->end_x = ray->ray_id;
	line->end_y = (WINDOW_HEIGHT / 2) + (wall_height / 2);

	// draw cieling
	cl_fr_line->start_x = line->start_x;
	cl_fr_line->start_y = 0;
	cl_fr_line->end_x = line->start_x;
	cl_fr_line->end_y = line->start_y;
	draw_line_2(mlx_info, cl_fr_line, GREEN);

	// north
	if (is_face_up(ray->ray_angle) && type == HORIZONTAL)
		draw_line_texture(mlx_info, ray, line, mlx_info->parse->no);
	// south
	else if (!is_face_up(ray->ray_angle) && type == HORIZONTAL)
		draw_line_texture(mlx_info, ray, line, mlx_info->parse->so);
	// east
	else if (is_face_right(ray->ray_angle) && type == VERTICAL)
		draw_vert_line_texture(mlx_info, ray, line, mlx_info->parse->ea);
	// west
	else if (!is_face_right(ray->ray_angle) && type == VERTICAL)
		draw_vert_line_texture(mlx_info, ray, line, mlx_info->parse->we);
	// draw floor

	cl_fr_line->start_x = line->start_x;
	cl_fr_line->start_y = line->end_y;
	cl_fr_line->end_x = line->start_x;
	cl_fr_line->end_y = WINDOW_HEIGHT;
	draw_line_2(mlx_info, cl_fr_line, RED);
}
