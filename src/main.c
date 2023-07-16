/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/15 19:02:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_mlx_info	mlx_info;

	init_mlx(&mlx_info);
	draw_mini_map(&mlx_info);
	mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win_ptr,
			mlx_info.img_data.img, 0, 0);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}
