/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:43:20 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/28 21:09:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_obstacles(t_game_data *game, double new_x, double new_y)
{
	double	x;
	double	y;

	x = new_x - 5;
	while (x <= new_x + 5)
	{
		y = new_y - 5;
		while (y <= new_y + 5)
		{
			if (check_wall((int)floor(x / SQUARE_SIZE), (int)floor(y
						/ SQUARE_SIZE), game->map))
				return (1);
			y += 1.0;
		}
		x += 1.0;
	}
	return (0);
}

void	rotate_right(t_game_data *game)
{
	game->player->player_vue += 0.05;
}

void	rotate_left(t_game_data *game)
{
	game->player->player_vue -= 0.05;
}
