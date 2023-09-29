/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:59:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 18:30:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	cast_one_ray(t_ray *ray, t_game_data *game)
{
	cast_vertically(ray, game);
	cast_horizontally(ray, game);
	draw_3d_line(game, ray);
}

int	cast_all_rays(t_game_data *game)
{
	int		i;
	double	delta_angle;
	t_ray	*ray;

	i = -1;
	delta_angle = FOV_ANGLE / WINDOW_WIDTH;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (ft_error("Failed to allocate memory for ray\n"));
	ray->ray_angle = game->player->player_vue - (FOV_ANGLE / 2);
	while (++i < WINDOW_WIDTH)
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
	}
	return (free(ray), 0);
}
