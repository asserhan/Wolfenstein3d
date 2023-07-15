/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:57:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/15 10:05:41 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

struct						s_img_data
{
	void					*img;
	char					*addr;
	int						bpp;
	int						size_line;
	int						endian;
};

typedef struct s_mlx_info
{
	void					*mlx_ptr;
	void					*win_ptr;
	struct s_img_data		img_data;
}							t_mlx_info;

#endif