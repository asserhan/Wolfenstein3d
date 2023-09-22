/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:58:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 18:38:27 by otait-ta         ###   ########.fr       */
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

void draw_texture(mlx_image_t *img, int x, int height, int texture)
{
    int y;
    int color;

    if (texture == NORTH)
        color = 0x00045781;
    else if (texture == SOUTH)
        color = 0x00F15F41;
    else if (texture == EAST)
        color = 0xFF0000FF;
    else if (texture == WEST)
        color = 0x000047E6;
    y = 0;
    while (y < (WINDOW_HEIGHT / 2) - (height / 2))
    {
        mlx_put_pixel(img, x, y, 0x000000FF);
        y++;
    }
    while (y < (WINDOW_HEIGHT / 2) + (height / 2))
    {
        mlx_put_pixel(img, x, y, color);
        y++;
    }
    while (y < WINDOW_HEIGHT)
    {
        mlx_put_pixel(img, x, y, 0x001000FF);
        y++;
    }

    // draw_pixel_no_scale(img, x, y, color);
}

void draw_line(t_game_data *game, t_ray *ray, int texture)
{
    double line_height;
    line_height = get_line_height(game, ray);
    if (texture == NORTH)
        draw_texture(game->img, ray->id, line_height, NORTH);
    else if (texture == SOUTH)
        draw_texture(game->img, ray->id, line_height, SOUTH);
    else if (texture == EAST)
        draw_texture(game->img, ray->id, line_height, EAST);
    else if (texture == WEST)
        draw_texture(game->img, ray->id, line_height, WEST);
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