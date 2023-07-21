/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/21 12:06:06 by otait-ta         ###   ########.fr       */
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

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img_data;

typedef struct s_player
{
	// to change names
	double			x;
	double			y;
	double			angle;
	double			turn_direction;
	double			walk_direction;
	double			rotation_angle;
	int				facing_up;
	int				facing_right;
	double			move_speed;
	double			rotation_speed;
}					t_player;

typedef struct s_mlx_info
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img_data		img_data;
	struct s_player	*player;
	char			**map;
}					t_mlx_info;

void				init_mlx(t_mlx_info *mlx_info);
void				init_player(t_player *player);
void				draw_pixel(t_mlx_info *info, int x, int y, int color);
void				draw_pixel_no_scale(t_mlx_info *info, int x, int y,
						int color);
/*pixel_cord : [0] for x , [1] for y*/
void				draw_square(t_mlx_info *mlx_info, int *pixel_cord,
						int square_size, int color);
void				draw_circle(t_mlx_info *mlx_info, int *pixel_cord,
						int radius, int color);
void				draw_mini_map(t_mlx_info *mlx_info, char **map);
int					wall_check(char **map, int x, int y);
void				draw_player(t_mlx_info *mlx_info, t_player *player);
void				draw_line(t_mlx_info *mlx_info, int *start_pixel_cord,
						double *end_pixel_cord, int color);
int					key_hook(int key, t_mlx_info *info);
void				move_forward(t_mlx_info *info);
void				move_backward(t_mlx_info *info);
void				cast_all_rays(t_mlx_info *mlx_info);
double				normalize_angle(double angle_radians);
int					is_face_up(double angle);
int					is_face_right(double angle);
int					distance_between_points(double x1, double y1, double x2,
						double y2);
void				draw_3d_line(t_mlx_info *mlx_info, int *p_cords,
						double *ray_cords, int ray_id, double ray_angle);
void	draw_line_2(t_mlx_info *mlx_info,
					double *start_pixel_cord,
					double *end_pixel_cord,
					int color);
/**********************CONSTANTS*******************************/

# define SQUARE_SIZE 84

# define RED 0
# define GREEN 1
# define BLUE 2

# define GRID_COLS 28
# define GRID_ROWS 12
# define MAP_SCALE 0.2

# define WINDOW_WIDTH (GRID_COLS * SQUARE_SIZE)
# define WINDOW_HEIGHT (GRID_ROWS * SQUARE_SIZE)
# define FOV_ANGLE (60 * (M_PI / 180))
# define NUM_RAYS WINDOW_WIDTH

# define VERTICAL 0
# define HORIZONTAL 1

#endif