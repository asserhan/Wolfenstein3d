/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/18 12:11:29 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define white_spaces " \t\n\v\f\r"
#define Wall 1

/**********************Parsing*******************************/

/******get_next_line********/
#define BUFFER_SIZE 50
char *get_next_line(int fd);
size_t ft_strlen(const char *s);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
char *read_and_add(int fd, char *reserve);
char *update_reserve(char **reserve, int i);
char *extract(char **reserve);

/***************************/
typedef struct t_rgb
{
	int r;
	int g;
	int b;
} t_rgb;

typedef struct s_parse
{
	char **info;
	char *no;
	char *so;
	char *we;
	char *ea;
	t_rgb f;
	t_rgb c;
	int in;
	int map_found;

} t_parse;
typedef struct s_map
{
	int player_x;
	int player_y;
	char player_vue;
	int rows;
	int cols;
	int player_num;
	char **map;
	int c;
	char *f_line;
} t_map;

int ft_error(char *str);
int ft_strcmp(const char *s1, const char *s2);
void free_matrix(char **tab);
void print_matrix(char **tab);
int check_file(char *file);
int check_char(t_map *map);
char *skip_spaces(char *line);
char **get_map(t_map *map, char *file);
int check_borders(t_map *map);
int ft_parsing(t_parse *parse, int fd, t_map *map);
int is_wall(char *line);
/**********************************************************/

typedef struct s_img_data
{
	void *img;
	char *addr;
	int bpp;
	int size_line;
	int endian;
} t_img_data;
typedef struct s_tex_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	int width;
	int height;
} t_tex_data;
typedef struct s_all_tex
{
	t_tex_data *no;
	t_tex_data *so;
	t_tex_data *we;
	t_tex_data *ea;
} t_all_tex;

typedef struct s_player
{
	// to change names
	double x;
	double y;
	double angle;
	double turn_direction;
	double walk_direction;
	double rotation_angle;
	int facing_up;
	int facing_right;
	double move_speed;
	double rotation_speed;
} t_player;

typedef struct s_ray
{
	double ray_angle;
	int ray_id;
	double wall_hit_x;
	double wall_hit_y;

} t_ray;
typedef struct s_line
{
	double start_x;
	double start_y;
	double end_x;
	double end_y;
} t_line;

typedef struct s_mlx_info
{
	void *mlx_ptr;
	void *win_ptr;
	t_img_data img_data;
	struct s_player *player;
	t_map *map_info;
	t_parse *parse;
	t_all_tex *all_tex;
} t_mlx_info;

void init_mlx(t_mlx_info *mlx_info);
void init_player(t_player *player);
void draw_pixel(t_mlx_info *info, int x, int y, int color);
void draw_pixel_no_scale(t_mlx_info *info, int x, int y,
						 int color);
/*pixel_cord : [0] for x , [1] for y*/
void draw_square(t_mlx_info *mlx_info, int *pixel_cord,
				 int square_size, int color);
void draw_circle(t_mlx_info *mlx_info, int *pixel_cord,
				 int radius, int color);
void draw_mini_map(t_mlx_info *mlx_info, char **map);
int wall_check(t_map *map_info, int x, int y);
void draw_player(t_mlx_info *mlx_info, t_player *player);
void draw_line(t_mlx_info *mlx_info, int *start_pixel_cord,
			   double *end_pixel_cord, int color);
int key_hook(int key, t_mlx_info *info);
void move_forward(t_mlx_info *info);
void move_backward(t_mlx_info *info);
void move_right(t_mlx_info *info);
void move_left(t_mlx_info *info);
void cast_all_rays(t_mlx_info *mlx_info);
double normalize_angle(double angle_radians);
int is_face_up(double angle);
int is_face_right(double angle);
int distance_between_points(double x1, double y1, double x2,
							double y2);

void draw_texture(t_ray *ray, t_mlx_info *mlx_info, int type);

void draw_line_2(t_mlx_info *mlx_info, t_line *line, int color);
void draw_pixel_texture(t_mlx_info *info, int x, int y, char *color);
void init_all_tex(t_all_tex *all_tex, t_mlx_info *mlx_info);
/**********************CONSTANTS*******************************/

#define SQUARE_SIZE 32

#define RED 0
#define GREEN 1
#define BLUE 2

#define GRID_COLS 28
#define GRID_ROWS 12
#define MAP_SCALE 0.2

#define WINDOW_WIDTH (GRID_COLS * SQUARE_SIZE)
#define WINDOW_HEIGHT (GRID_ROWS * SQUARE_SIZE)
#define FOV_ANGLE (60 * (M_PI / 180))
#define NUM_RAYS WINDOW_WIDTH

#define VERTICAL 0
#define HORIZONTAL 1

#endif