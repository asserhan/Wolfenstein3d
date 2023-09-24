/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_horizantally.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:53:34 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/23 22:45:17 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void cast_horizontally(t_ray *ray, t_game_data *game)
{
    double x_intercept;
    double y_intercept;
    double x_step;
    double y_step;
    int x_to_check;
    int y_to_check;

    y_intercept = floor(game->player->y / SQUARE_SIZE) * SQUARE_SIZE;
    y_step = SQUARE_SIZE;
    if (ray->is_facing_down)
        y_intercept += SQUARE_SIZE;
    if (ray->is_facing_up)
        y_step *= -1;
    x_intercept = game->player->x + (y_intercept - game->player->y) / tan(ray->ray_angle);
    x_step = SQUARE_SIZE / tan(ray->ray_angle);
    if (ray->is_facing_left && x_step > 0)
        x_step *= -1;
    if (ray->is_facing_right && x_step < 0)
        x_step *= -1;
    while (x_intercept >= 0 && x_intercept <= game->map->cols * SQUARE_SIZE && y_intercept >= 0 && y_intercept <= game->map->rows * SQUARE_SIZE)
    {
        if (ray->is_facing_up)
        {
            x_to_check = floor(x_intercept / SQUARE_SIZE);
            y_to_check = floor((y_intercept - 1) / SQUARE_SIZE);
        }
        else
        {
            x_to_check = floor(x_intercept / SQUARE_SIZE);
            y_to_check = floor((y_intercept + 1) / SQUARE_SIZE);
        }

        if (check_wall(x_to_check, y_to_check, game->map))
        {
            if (ray->was_hit_vertical && distance_between_points(game->player->x, game->player->y, x_intercept, y_intercept) >= ray->distance)
                return;
            ray->was_hit_vertical = 0;
            ray->wall_hit_x = x_intercept;
            ray->wall_hit_y = y_intercept;
            ray->distance = distance_between_points(game->player->x, game->player->y, x_intercept, y_intercept);
            ray->was_hit_horizontal = 1;
            return;
        }
        else
        {
            x_intercept += x_step;
            y_intercept += y_step;
        }
    }
    ray->was_hit_horizontal = 0;
}
