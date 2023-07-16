/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/16 09:06:48 by otait-ta         ###   ########.fr       */
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

typedef struct s_mlx_info
{
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_img_data	img_data;
}						t_mlx_info;

void					init_mlx(t_mlx_info *mlx_info);
void					draw_pixel(t_mlx_info *info, int x, int y, int color);
void					draw_square(t_mlx_info *mlx_info, int x_pixel_start,
							int y_pixel_start, int square_size);
void					draw_mini_map(t_mlx_info *mlx_info);
/**********************CONSTANTS*******************************/

# define SQUARE_SIZE 32

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 360

# define RED 0
# define GREEN 1
# define BLUE 2

# define GRID_COLS 12
# define GRID_ROWS 5

#endif