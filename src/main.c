/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/15 10:37:50 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_mlx_info	mlx_info;

	mlx_info.mlx_ptr = mlx_init();
	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, 500, 500,
			"Hello world!");
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}
