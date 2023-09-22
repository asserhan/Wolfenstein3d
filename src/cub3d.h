/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/22 15:27:04 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "/Users/hasserao/Desktop/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# define white_spaces " \t\n\v\f\r"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

/****************************Parsing*******************************/

/******get_next_line********/
# define BUFFER_SIZE 1

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*read_and_add(int fd, char *reserve);
char		*update_reserve(char **reserve, int i);
char		*extract(char **reserve);

/***************************/
typedef struct t_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_parse
{
	char	**info;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	f;
	t_rgb	c;
	int		in;
	int		map_found;

}			t_parse;
typedef struct s_map
{
	int		player_x;
	int		player_y;
	char	player_vue;
	int		rows;
	int		cols;
	int		player_num;
	char	**map;
	int		c;
	char	*f_line;
}			t_map;

int			ft_error(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		free_matrix(char **tab);
void		print_matrix(char **tab);
int			check_file(char *file);
int			check_char(char c);
char		*skip_spaces(char *line);
char		**get_map(t_map *map, char *file);
int			check_borders(t_map *map);
int			ft_parsing(t_parse *parse, int fd, t_map *map);
int			is_wall(char *line);

/*************************Minilibx*********************************/


void ft_erno(void);

/*************************Reycasting*********************************/


typedef struct s_player
{
	// to change names
	t_map	*map;
	double	x_player;
	double	y_player;
	double	angle;
	double	left_right;
	double	up_down;
	double	turn_angle;
	double	speed;
	double	turn_speed;
}			t_player;



#endif