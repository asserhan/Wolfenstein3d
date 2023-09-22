/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:58:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 14:35:37 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double get_line_height(t_game_data *game, t_ray *ray)
{
    double ray_dist;
    double dist_to_plane;
    double line_height;
    (void)game;
    ray_dist = ray->distance;
    dist_to_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
    line_height = (SQUARE_SIZE / ray_dist) * dist_to_plane;
    return (line_height);
}

void draw_texture(mlx_image_t *img, int x, int height, int texture)
{
    int y;
    int color;

    if (texture == NORTH)
        color = 0x00FF00FF;
    else if (texture == SOUTH)
        color = 0x0000FFFF;
    else if (texture == EAST)
        color = 0xFF0000FF;
    else if (texture == WEST)
        color = 0x000000FF;

    y = (WINDOW_HEIGHT / 2) - (height / 2);
    while (y < (WINDOW_HEIGHT / 2) + (height / 2))
    {
        mlx_put_pixel(img, x, y, color);
        y++;
    }

    // draw_pixel_no_scale(img, x, y, color);
}

void draw_line(t_game_data *game, t_ray *ray, int texture)
{
    double line_height;
    (void)texture;
    line_height = get_line_height(game, ray);
    printf("line_height: %f\n", ray->distance);
    // if (texture == NORTH)
    //     draw_texture(game->img, ray->id, line_height, NORTH);
    // else if (texture == SOUTH)
    //     draw_texture(game->img, ray->id, line_height, SOUTH);
    // else if (texture == EAST)
    //     draw_texture(game->img, ray->id, line_height, EAST);
    // else if (texture == WEST)
    //     draw_texture(game->img, ray->id, line_height, WEST);
}
void draw_3d_line(t_game_data *game, t_ray *ray)
{
    (void)game;
    if (ray->was_hit_vertical && ray->is_facing_right)
        draw_line(game, ray, EAST);
    if (ray->was_hit_vertical && ray->is_facing_left)
        draw_line(game, ray, WEST);
    // if (ray->was_hit_horizontal && ray->is_facing_up)
    //     draw_line(game, ray, NORTH);
    // else if (ray->was_hit_horizontal && ray->is_facing_down)
    //     draw_line(game, ray, SOUTH);
}