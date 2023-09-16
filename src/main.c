/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:01:19 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/16 19:03:51 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error(char *str)
{

	ft_printf("Error\n");
	ft_putstr_fd(str, 2);
	return (1);
}
void init_file(t_parse *parse, t_map *map)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	map->map = malloc(sizeof(char *) * 20000);
	if (!map->map)
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
	parse->in = 0;
	parse->map_found = 0;
	map->rows = 0;
	map->cols = 0;
	map->c = 0;
}
int main(int argc, char **argv)
{
	t_map maps;
	t_parse parse;
	int fd;
	// int fd;
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ft_error("Invalid file\n"), 1);
		if ((fd = open(argv[1], O_DIRECTORY) != -1))
			return (ft_error("Is a directory\n"), 1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("file does not open\n"), 1);
		init_file(&parse, &maps);
		if (ft_parsing(&parse, fd, &maps))
			exit(1);

		// get_map(&maps,fd);
		t_mlx_info mlx_info;
		t_player player;
		char **map;

		mlx_info.parse = &parse;
		map = (char **)malloc(sizeof(char *) * 12);
		map[0] = "111111111111111111111111111";
		map[1] = "100001000000000000000000001";
		map[2] = "100001000000000000000000001";
		map[3] = "100001000000000000000000001";
		map[4] = "100001000000000000000000001";
		map[5] = "100001000000100000000000001";
		map[6] = "100001000000010000000000001";
		map[7] = "100001000000000000000000001";
		map[8] = "100001000000000000000000001";
		map[9] = "100001000000000000000000001";
		map[10] = "100001000000000000000000001";
		map[11] = "111111111111111111111111111";
		init_mlx(&mlx_info);
		init_player(&player);
		mlx_info.player = &player;
		mlx_info.map = map;
		cast_all_rays(&mlx_info);
		draw_mini_map(&mlx_info, map);
		draw_player(&mlx_info, &player);
		mlx_hook(mlx_info.win_ptr, 2, 1L << 0, key_hook, &mlx_info);
		mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win_ptr,
								mlx_info.img_data.img, 0, 0);
		mlx_loop(mlx_info.mlx_ptr);
		return (0);
	}
	else
		ft_error("Invalid number of arguments\n");
	return (0);
}
