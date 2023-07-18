/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/18 11:53:41 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct					s_img_data
{
	void				*img;
	char				*addr;
	int					bpp;
	int					size_line;
	int					endian;
};

typedef struct s_player
{
	// to change names
	double				x;
	double				y;
	double				angle;
	double				turn_direction;
	double				walk_direction;
	double				rotation_angle;
	double				move_speed;
	double				rotation_speed;
}						t_player;

typedef struct s_mlx_info
{
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_img_data	img_data;
	struct s_player		*player;
	char				**map;
}						t_mlx_info;

void					init_mlx(t_mlx_info *mlx_info);
void					init_player(t_player *player);
void					draw_pixel(t_mlx_info *info, int x, int y, int color);
/*pixel_cord : [0] for x , [1] for y*/
void					draw_square(t_mlx_info *mlx_info, int *pixel_cord,
							int square_size, int color);
void					draw_circle(t_mlx_info *mlx_info, int *pixel_cord,
							int radius, int color);
void					draw_mini_map(t_mlx_info *mlx_info, char **map);
void					draw_player(t_mlx_info *mlx_info, t_player *player);
void					draw_line(t_mlx_info *mlx_info, int *start_pixel_cord,
							double *end_pixel_cord, int color);
int						key_hook(int key, t_mlx_info *info);
/**********************CONSTANTS*******************************/

# define SQUARE_SIZE 32

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 360

# define RED 0
# define GREEN 1
# define BLUE 2

# define GRID_COLS 13
# define GRID_ROWS 5

#endif