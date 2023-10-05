/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:01:19 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 18:30:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"   

void	draw_texture(t_game_data *game, t_ray *ray, int height, int texture)
{
	int	y;

	y = 0;
	while (y < (WINDOW_HEIGHT / 2) - (height / 2))
	{
		mlx_put_pixel(game->img, ray->id, y, get_rgba(game->map->ceiling.r,
				game->map->ceiling.g, game->map->ceiling.b, 255));
		y++;
	}
	draw_line_texture(game, ray, height, texture);
	y = (WINDOW_HEIGHT / 2) + (height / 2);
	while (y < WINDOW_HEIGHT)
	{
		mlx_put_pixel(game->img, ray->id, y, get_rgba(game->map->floor.r,
				game->map->floor.g, game->map->floor.b, 255));
		y++;
	}
}

void	draw_line(t_game_data *game, t_ray *ray, int texture)
{
	double	line_height;

	line_height = get_line_height(game, ray);
	draw_texture(game, ray, line_height, texture);
}

void	draw_3d_line(t_game_data *game, t_ray *ray)
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
