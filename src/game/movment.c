/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:49:56 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/23 16:13:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

// Define a function to check for obstacles in the path of movement
int check_obstacles(t_game_data *game, double new_x, double new_y)
{
    // Calculate the bounding box of the square around the player's new position
    double left = new_x - 5;
    double right = new_x + 5;
    double top = new_y - 5;
    double bottom = new_y + 5;

    // Initialize collision flag to false
    int collision = 0;

    // Iterate through the pixels in the bounding box using a while loop
    double x = left;
    while (x <= right && !collision)
    {
        double y = top;
        while (y <= bottom && !collision)
        {
            // Check if there is an obstacle at the current pixel
            if (check_wall((int)floor(x / SQUARE_SIZE), (int)floor(y / SQUARE_SIZE), game->map))
            {
                collision = 1; // Collision detected, exit the loop
            }
            y += 1.0; // Move to the next pixel in the vertical direction
        }
        x += 1.0; // Move to the next pixel in the horizontal direction
    }

    return collision; // Return true if a collision was detected, false otherwise
}

void move_forward(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue) * 1.5;
    new_y = game->player->y + sin(game->player->player_vue) * 1.5;

    if (!check_obstacles(game, new_x, new_y))
    {
        // No obstacles, move the player
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void move_backward(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x - cos(game->player->player_vue) * 1.5;
    new_y = game->player->y - sin(game->player->player_vue) * 1.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        // No obstacles, move the player
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void move_right(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue + M_PI_2) * 1.5;
    new_y = game->player->y + sin(game->player->player_vue + M_PI_2) * 1.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        // No obstacles, move the player
        game->player->x = new_x;
        game->player->y = new_y;
    }
}
void move_left(t_game_data *game)
{
    double new_x;
    double new_y;
    new_x = game->player->x + cos(game->player->player_vue - M_PI_2) * 1.5;
    new_y = game->player->y + sin(game->player->player_vue - M_PI_2) * 1.5;
    if (!check_obstacles(game, new_x, new_y))
    {
        // No obstacles, move the player
        game->player->x = new_x;
        game->player->y = new_y;
    }
}

void rotate_right(t_game_data *game)
{
    game->player->player_vue += 0.05;
}

void rotate_left(t_game_data *game)
{
    game->player->player_vue -= 0.05;
}