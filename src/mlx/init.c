/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:50:58 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/21 16:10:25 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_erno(void)
{
    printf("%s\n",mlx_strerror(mlx_errno));
    exit(1);
}
void ft_inti_mlx(t_mlx *mlx)
{
    mlx->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D",true);
    if (!mlx->mlx)
        ft_erno();
    mlx->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

}