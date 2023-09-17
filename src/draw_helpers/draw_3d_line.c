/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:11:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/17 14:22:47 by otait-ta         ###   ########.fr       */
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

void draw_line_texture(t_mlx_info *mlx_info, t_ray *ray, t_line *line, t_tex_data *tex_data)
{

	// Endianness

	// get the color of the pixel at the x,y coordinates
	double tile_x;
	double tex_x;

	tile_x = fmod(ray->wall_hit_x, SQUARE_SIZE);
	tex_x = (tile_x / SQUARE_SIZE) * tex_data->width;
	int tex_y = 0;
	double y = line->start_y;
	while (y < line->end_y)
	{
		tex_y = (y - line->start_y) * (tex_data->height / (line->end_y - line->start_y));
		char *color = get_pixel_color(tex_data, tex_x, tex_y);
		draw_pixel_texture(mlx_info, line->start_x, y, color);
		y++;
	}
}
void draw_vert_line_texture(t_mlx_info *mlx_info, t_ray *ray, t_line *line, t_tex_data *tex_data)
{

	// Endianness

	// get the color of the pixel at the x,y coordinates
	double tile_y;
	double tex_x;

	tile_y = fmod(ray->wall_hit_y, SQUARE_SIZE);
	tex_x = (tile_y / SQUARE_SIZE) * tex_data->width;
	int tex_y = 0;
	double y = line->start_y;
	while (y < line->end_y)
	{
		tex_y = (y - line->start_y) * (tex_data->height / (line->end_y - line->start_y));
		char *color = get_pixel_color(tex_data, tex_x, tex_y);
		draw_pixel_texture(mlx_info, line->start_x, y, color);
		y++;
	}
}

void init_all_tex(t_all_tex *all_tex, t_mlx_info *mlx_info)
{
	all_tex->no = (t_tex_data *)malloc(sizeof(t_tex_data));
	all_tex->no->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, mlx_info->parse->no, &all_tex->no->width, &all_tex->no->height);
	if (all_tex->no->img == NULL)
	{
		printf("Error in texture pointer\n");
		exit(1);
	}
	all_tex->no->addr = mlx_get_data_addr(all_tex->no->img, &all_tex->no->bits_per_pixel, &all_tex->no->size_line, &all_tex->no->endian);

	all_tex->so = (t_tex_data *)malloc(sizeof(t_tex_data));
	all_tex->so->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, mlx_info->parse->so, &all_tex->so->width, &all_tex->so->height);
	if (all_tex->so->img == NULL)
	{
		printf("Error in texture pointer\n");
		exit(1);
	}
	all_tex->so->addr = mlx_get_data_addr(all_tex->so->img, &all_tex->so->bits_per_pixel, &all_tex->so->size_line, &all_tex->so->endian);

	all_tex->ea = (t_tex_data *)malloc(sizeof(t_tex_data));
	all_tex->ea->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, mlx_info->parse->ea, &all_tex->ea->width, &all_tex->ea->height);
	if (all_tex->ea->img == NULL)
	{
		printf("Error in texture pointer\n");
		exit(1);
	}
	all_tex->ea->addr = mlx_get_data_addr(all_tex->ea->img, &all_tex->ea->bits_per_pixel, &all_tex->ea->size_line, &all_tex->ea->endian);

	all_tex->we = (t_tex_data *)malloc(sizeof(t_tex_data));
	all_tex->we->img = mlx_xpm_file_to_image(mlx_info->mlx_ptr, mlx_info->parse->we, &all_tex->we->width, &all_tex->we->height);
	if (all_tex->we->img == NULL)
	{
		printf("Error in texture pointer\n");
		exit(1);
	}
	all_tex->we->addr = mlx_get_data_addr(all_tex->we->img, &all_tex->we->bits_per_pixel, &all_tex->we->size_line, &all_tex->we->endian);
}

void draw_texture(t_ray *ray, t_mlx_info *mlx_info, int type)
{
	double ray_dist;
	double wall_height;
	double dist_to_plane;

	t_line *line;
	t_line *cl_fr_line;
	t_all_tex *all_tex;

	all_tex = mlx_info->all_tex;

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
		draw_line_texture(mlx_info, ray, line, all_tex->no);
	// south
	else if (!is_face_up(ray->ray_angle) && type == HORIZONTAL)
		draw_line_texture(mlx_info, ray, line, all_tex->so);
	// east
	else if (is_face_right(ray->ray_angle) && type == VERTICAL)
		draw_vert_line_texture(mlx_info, ray, line, all_tex->ea);
	// west
	else if (!is_face_right(ray->ray_angle) && type == VERTICAL)
		draw_vert_line_texture(mlx_info, ray, line, all_tex->we);
	// draw floor
	cl_fr_line->start_x = line->start_x;
	cl_fr_line->start_y = line->end_y;
	cl_fr_line->end_x = line->start_x;
	cl_fr_line->end_y = WINDOW_HEIGHT;
	draw_line_2(mlx_info, cl_fr_line, RED);
}
