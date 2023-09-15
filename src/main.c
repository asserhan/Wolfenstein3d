/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/14 18:05:04 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error(char *str)
{
	ft_printf("Error\n");
	ft_putstr_fd(str,2);
	return(1);
}
void init_file(t_parse *parse,t_map *map)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	map->map = malloc(sizeof(char *) * 20000);
	if(!map->map)
	{
		free_matrix(map->map);
		free(map);
	}
	map->f_line = NULL;
	map->player_x = 0;
	map->player_y = 0;
	parse->f.b = -1;
	parse->f.g = -1;
	parse->f.r = -1;
	parse->c.b = -1;
	parse->c.g = -1;
	parse->c.r = -1;
	parse->in=0;
	parse->map_found = 0;
	map->rows = 0;
	map->cols = 0;
	map->c = 0;
	
	
}
int main(int argc,char **argv)
{
	t_map maps;
	t_parse parse;
    int fd;
	//int fd;
	if(argc == 2)
	{
		if(check_file(argv[1]))
        	return(ft_error("Invalid file\n"),1);
		if((fd = open(argv[1],O_DIRECTORY) != -1))
			return(ft_error("Is a directory\n"),1);	
   		if((fd = open (argv[1],O_RDONLY)) == -1)
			return(ft_error("file does not open\n"),1);
		init_file(&parse,&maps);
		ft_parsing(&parse,fd,&maps);
		//get_map(&maps,fd); 
	}
	else
		ft_error("Invalid number of arguments\n");
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
