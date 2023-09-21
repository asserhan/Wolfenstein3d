/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:04:50 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/21 19:22:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void mlx_draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color)
{
    (void)color;
    int i;
    int j;

    i = 0;

    // make border black and fill inside with color
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                mlx_put_pixel(img, x + i, y + j, 0x000000FF);
            else
                mlx_put_pixel(img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}