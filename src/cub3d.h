/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/03 16:43:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WHITE_SPACES " \t\n\v\f\r"
#define BUFFER_SIZE 1
#define SQUARE_SIZE 32
#define FOV_ANGLE 1.0471975512
#define WINDOW_WIDTH 1440
#define WINDOW_HEIGHT 960

#define RED 0
#define GREEN 1
#define BLUE 2

#define GRID_COLS 13
#define GRID_ROWS 5

#define FORWARD 1
#define BACKWARD -1
#define RIGHT 2
#define LEFT -2

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

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
	int valid;

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
	mlx_texture_t **textures;
	t_rgb floor;
	t_rgb ceiling;

} t_map;

/**********************************/

typedef struct s_player
{
	double x;
	double y;
	double player_vue;
	double move_speed;
	double rotation_speed;
} t_player;

typedef struct s_game_data
{
	mlx_image_t *img;
	t_player *player;
	t_map *map;
	mlx_t *mlx;
	t_parse *parse;
	int prev_x;
} t_game_data;

typedef struct s_ray
{
	int id;
	double ray_angle;
	double wall_hit_x;
	double wall_hit_y;
	double distance;
	int is_facing_up;
	int is_facing_down;
	int is_facing_right;
	int is_facing_left;
	int was_hit_vertical;
	int was_hit_horizontal;
} t_ray;
/**********************Parsing*******************************/

/******get_next_line********/

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

/************************/

int ft_error(char *str);
void free_resources(t_game_data *game);
void free_textures(t_game_data *game);
int check_digit(char **str);
int valid_comma(char *str);
char **matrix_push_back(char **matrix, char *back);
int matrix_size(char **tab);
int ft_strcmp(const char *s1, const char *s2);
void free_matrix(char **tab);
int check_file(char *file);
int check_char(char c);
char *skip_spaces(char *line);
int just_spaces(char *line);
char *check_path(char *line);
int check_spaces(t_map *map);
int north_path(t_parse *parse, char **tab, char *line);
int west_path(t_parse *parse, char **tab, char *line);
int south_path(t_parse *parse, char **tab, char *line);
int east_path(t_parse *parse, char **tab, char *line);
int ft_textures(t_parse *parse, char **tab, char *line);
void get_first_line(t_map *map, char *line, t_parse *parse);
int read_for_dimensions(t_map *map, char *line, int fd);
int find_size(t_map *map, int fd);
int get_color(t_parse *parse, char **tab);
int check_textures(t_parse *parse, char *line);
int get_map(t_map *map, char *file);
int check_borders(t_map *map);
int ft_parsing(t_parse *parse, int fd, t_map *map);
int is_wall(char *line);
void init_file(t_parse *parse, t_map *map);
/***************************/

/***REY CASTING*/

int init_game(mlx_t *mlx, t_game_data *game, t_parse *parse);
int check_obstacles(t_game_data *game, double new_x,
					double new_y);
void keyhook(void *param);
void mousehook(double a, double b, void *param);
void move_forward(t_game_data *game);
void move_backward(t_game_data *game);
void move_left(t_game_data *game);
void move_right(t_game_data *game);
void rotate_left(t_game_data *game);
void rotate_right(t_game_data *game);
void draw_texture(t_game_data *game, t_ray *ray, int height,
				  int texture);
void draw_line(t_game_data *game, t_ray *ray, int texture);
double normalize_angle(double angle);
int is_face_up(double angle);
int is_face_right(double angle);
double distance_between_points(double x1, double y1, double x2,
							   double y2);

int check_wall(int x, int y, t_map *map);
int get_rgba(int r, int g, int b, int a);
void draw_line_texture(t_game_data *game, t_ray *ray,
					   double height, int texture);
double get_line_height(t_game_data *game, t_ray *ray);
int cast_all_rays(t_game_data *game);
void cast_vertically(t_ray *ray, t_game_data *game);
void cast_horizontally(t_ray *ray, t_game_data *game);
void draw_3d_line(t_game_data *game, t_ray *ray);
void free_resources(t_game_data *game);

/**********************CONSTANTS*******************************/
#endif