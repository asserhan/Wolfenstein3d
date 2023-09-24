/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:58:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/24 20:03:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double get_line_height(t_game_data *game, t_ray *ray)
{
    double line_height;
    double distance_to_plane;

    distance_to_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
    ray->distance = ray->distance * cos(ray->ray_angle - game->player->player_vue);
    line_height = (SQUARE_SIZE / ray->distance) * distance_to_plane;
    return (line_height);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int get_pixel_color(mlx_texture_t *tex_data, uint32_t x, uint32_t y)
{
    int pixel_color;
    int index;

    if (x >= 0 && x < tex_data->width && y >= 0 && y < tex_data->height)
    {
        index = (y * tex_data->width + x) * tex_data->bytes_per_pixel;
        pixel_color = get_rgba(tex_data->pixels[index], tex_data->pixels[index + 1], tex_data->pixels[index + 2], tex_data->pixels[index + 3]);
    }
    else
        pixel_color = get_rgba(0, 0, 0, 255);
    return pixel_color;
}
void draw_line_texture(t_game_data *game, t_ray *ray, int height, int texture)
{

    double tile_x;
    double tex_x;
    double tex_y;
    double y_start;
    double y;

    y_start = (WINDOW_HEIGHT / 2) - (height / 2);
    if (texture == NORTH || texture == SOUTH)
        tile_x = fmod(ray->wall_hit_x, SQUARE_SIZE);
    else
        tile_x = fmod(ray->wall_hit_y, SQUARE_SIZE);
    tex_x = tile_x * (game->map->textures[texture]->width / SQUARE_SIZE);
    y = y_start;
    while (y < (WINDOW_HEIGHT / 2) + (height / 2))
    {
        if (ray->id >= 0 && ray->id < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
        {
            tex_y = (y - y_start) * (game->map->textures[texture]->height / ((y_start + height) - y_start));
            int color = get_pixel_color(game->map->textures[texture], tex_x, tex_y);
            mlx_put_pixel(game->img, ray->id, y, color);
        }
        y++;
    }
}

void draw_texture(t_game_data *game, t_ray *ray, int height, int texture)
{
    int y;

    y = 0;
    while (y < (WINDOW_HEIGHT / 2) - (height / 2))
    {
        mlx_put_pixel(game->img, ray->id, y, get_rgba(game->map->ceiling.r, game->map->ceiling.g, game->map->ceiling.b, 255));
        y++;
    }
    draw_line_texture(game, ray, height, texture);
    y = (WINDOW_HEIGHT / 2) + (height / 2);
    while (y < WINDOW_HEIGHT)
    {
        mlx_put_pixel(game->img, ray->id, y, get_rgba(game->map->floor.r, game->map->floor.g, game->map->floor.b, 255));
        y++;
    }
}

void draw_line(t_game_data *game, t_ray *ray, int texture)
{
    double line_height;
    line_height = get_line_height(game, ray);
    draw_texture(game, ray, line_height, texture);
}
void draw_3d_line(t_game_data *game, t_ray *ray)
{
    if (ray->was_hit_vertical && ray->is_facing_right)
        draw_line(game, ray, EAST);
    else if (ray->was_hit_vertical && ray->is_facing_left)
        draw_line(game, ray, WEST);
    else if (ray->was_hit_horizontal && ray->is_facing_up)
        draw_line(game, ray, NORTH);
    else if (ray->was_hit_horizontal && ray->is_facing_down)
        draw_line(game, ray, SOUTH);
}