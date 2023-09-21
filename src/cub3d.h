/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/21 20:47:47 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include "/Users/otait-ta/Desktop/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define white_spaces " \t\n\v\f\r"
#define Wall 1

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
	t_parse *parse;
} t_map;

/**********************************/

typedef struct s_player
{
	// to change names
	double x;
	double y;
	double turn_direction;
	double walk_direction;
	double player_vue;
	double move_speed;
	double rotation_speed;
} t_player;

typedef struct s_game_data
{

	mlx_image_t *img;
	t_player *player;
	t_map *map;
} t_game_data;

/**********************Parsing*******************************/

/******get_next_line********/
#define BUFFER_SIZE 1
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
int ft_strcmp(const char *s1, const char *s2);
void free_matrix(char **tab);
void print_matrix(char **tab);
int check_file(char *file);
int check_char(char c);
char *skip_spaces(char *line);
char **get_map(t_map *map, char *file);
int check_borders(t_map *map);
int ft_parsing(t_parse *parse, int fd, t_map *map);
int is_wall(char *line);
/***************************/

/***REY CASTING*/
void draw_mini_map(t_game_data *game);

int init_game(mlx_t *mlx, t_game_data *game, t_map *map);

void mlx_draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color);

void keyhook(mlx_key_data_t keydata, void *param);
/**********************CONSTANTS*******************************/

#define SQUARE_SIZE 32

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

#define RED 0
#define GREEN 1
#define BLUE 2

#define GRID_COLS 13
#define GRID_ROWS 5

#define FORWARD 1
#define BACKWARD -1
#define RIGHT 2
#define LEFT -2
#endif