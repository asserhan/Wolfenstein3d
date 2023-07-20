/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/19 14:42:26 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc,char **argv)
{
	t_map maps;
	if(argc == 2)
	{
		get_map(&maps,argv[1]); 
	}
	else
		ft_printf("Invalid argument\n");
	return(0);
}
// int	main(void)
// {
// 	t_mlx_info	mlx_info;
// 	t_player	player;
// 	char		**map;

// 	map = (char **)malloc(sizeof(char *) * 5);
// 	map[0] = "111111111111";
// 	map[1] = "100000000001";
// 	map[2] = "100001100001";
// 	map[3] = "101000000001";
// 	map[4] = "111111111111";
// 	init_mlx(&mlx_info);
// 	init_player(&player);
// 	mlx_info.player = &player;
// 	mlx_info.map = map;
// 	draw_mini_map(&mlx_info, map);
// 	draw_player(&mlx_info, &player);
// 	mlx_hook(mlx_info.win_ptr, 2, 1L << 0, key_hook, &mlx_info);
// 	mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win_ptr,
// 			mlx_info.img_data.img, 0, 0);
// 	mlx_loop(mlx_info.mlx_ptr);
// 	return (0);
// }
