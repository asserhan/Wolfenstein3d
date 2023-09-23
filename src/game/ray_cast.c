/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:59:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/23 09:33:23 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void cast_one_ray(t_ray *ray, t_game_data *game)
{
    cast_vertically(ray, game);
    cast_horizontally(ray, game);
    draw_3d_line(game, ray);
}

void cast_all_rays(t_game_data *game)
{
    int i;
    double delta_angle;
    t_ray *ray;

    i = 0;
    delta_angle = FOV_ANGLE / WINDOW_WIDTH;
    // TODO: free ray
    ray = malloc(sizeof(t_ray));
    ray->ray_angle = game->player->player_vue - (FOV_ANGLE / 2);

    while (i < WINDOW_WIDTH)
    {
        ray->ray_angle = normalize_angle(ray->ray_angle);
        ray->is_facing_up = is_face_up(ray->ray_angle);
        ray->is_facing_down = !ray->is_facing_up;
        ray->is_facing_right = is_face_right(ray->ray_angle);
        ray->is_facing_left = !ray->is_facing_right;
        ray->was_hit_horizontal = 0;
        ray->was_hit_vertical = 0;
        ray->distance = 0;
        ray->id = i;
        cast_one_ray(ray, game);
        ray->ray_angle += delta_angle;
        i++;
    }
}