/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:42:19 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 20:57:26 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_resources(t_game_data *game)
{
	free_matrix(game->map->map);
	free_textures(game);
	free(game->map);
	free(game->player);
	free(game->map->textures);
	free(game->parse->no);
	free(game->parse->so);
	free(game->parse->we);
	free(game->parse->ea);
	free(game->parse);
	free(game);
}

void	free_textures(t_game_data *game)
{
	if (game->map->textures)
	{
		if (game->map->textures[NORTH])
		{
			free(game->map->textures[NORTH]->pixels);
			free(game->map->textures[NORTH]);
		}
		if (game->map->textures[SOUTH])
		{
			free(game->map->textures[SOUTH]->pixels);
			free(game->map->textures[SOUTH]);
		}
		if (game->map->textures[EAST])
		{
			free(game->map->textures[EAST]->pixels);
			free(game->map->textures[EAST]);
		}
		if (game->map->textures[WEST])
		{
			free(game->map->textures[WEST]->pixels);
			free(game->map->textures[WEST]);
		}
	}
}
