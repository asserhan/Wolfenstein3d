/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vertically.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:32:40 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 18:30:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_ver_interceptions(double x_intercept, double y_intercept, t_ray *ray,
		t_game_data *game)
{
	int	x_to_check;
	int	y_to_check;

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
		ray->distance = distance_between_points(game->player->x,
				game->player->y, x_intercept, y_intercept);
		ray->was_hit_vertical = 1;
		return (1);
	}
	return (0);
}

void	y_steps(t_ray *ray, double *y_steps)
{
	*y_steps = SQUARE_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && *y_steps > 0)
		*y_steps *= -1;
	if (ray->is_facing_down && *y_steps < 0)
		*y_steps *= -1;
}

void	cast_vertically(t_ray *ray, t_game_data *game)
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	x_intercept = floor(game->player->x / SQUARE_SIZE) * SQUARE_SIZE;
	x_step = SQUARE_SIZE;
	if (ray->is_facing_right)
		x_intercept += SQUARE_SIZE;
	if (ray->is_facing_left)
		x_step *= -1;
	y_intercept = game->player->y + (x_intercept - game->player->x)
		* tan(ray->ray_angle);
	y_steps(ray, &y_step);
	while (x_intercept >= 0 && x_intercept < game->map->cols * SQUARE_SIZE
		&& y_intercept >= 0 && y_intercept < game->map->rows * SQUARE_SIZE)
	{
		if (check_ver_interceptions(x_intercept, y_intercept, ray, game))
			return ;
		x_intercept += x_step;
		y_intercept += y_step;
	}
	ray->was_hit_vertical = 0;
}
