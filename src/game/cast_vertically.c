/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vertically.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:41:28 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 10:41:29 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void cast_vertically(t_ray *ray, t_game_data *game)
{
    double x_intercept;
    double y_intercept;
    double x_step;
    double y_step;
    int x_to_check;
    int y_to_check;

    x_intercept = floor(game->player->x / SQUARE_SIZE) * SQUARE_SIZE;
    x_step = SQUARE_SIZE;
    if (ray->is_facing_right)
        x_intercept += SQUARE_SIZE;
    if (ray->is_facing_left)
        x_step *= -1;
    y_intercept = game->player->y + (x_intercept - game->player->x) * tan(ray->ray_angle);
    y_step = SQUARE_SIZE * tan(ray->ray_angle);
    if (ray->is_facing_up && y_step > 0)
        y_step *= -1;
    if (ray->is_facing_down && y_step < 0)
        y_step *= -1;

    while (x_intercept >= 0 && x_intercept < game->map->cols * SQUARE_SIZE && y_intercept >= 0 && y_intercept < game->map->rows * SQUARE_SIZE)
    {
        if (ray->is_facing_right)
        {
            x_to_check = floor((x_intercept + 1) / SQUARE_SIZE);
            y_to_check = floor(y_intercept / SQUARE_SIZE);
        }
        else
        {
            x_to_check = floor((x_intercept - 1) / SQUARE_SIZE);
            y_to_check = floor(y_intercept / SQUARE_SIZE);
        }

        if (check_wall(x_to_check, y_to_check, game->map))
        {
            ray->wall_hit_x = x_intercept;
            ray->wall_hit_y = y_intercept;
            ray->distance = distance_between_points(game->player->x, game->player->y, x_intercept, y_intercept);
            ray->was_hit_vertical = 1;
            return;
        }
        else
        {
            x_intercept += x_step;
            y_intercept += y_step;
        }
    }
    ray->was_hit_vertical = 0;
}
