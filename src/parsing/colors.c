/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:32:58 by hasserao          #+#    #+#             */
/*   Updated: 2023/10/03 17:35:13 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_floor(t_parse *parse, char **rgb)
{
	if (parse->f.r != -1 || parse->f.g != -1 || parse->f.b != -1)
		return (free_matrix(rgb), ft_error("in colors\n"));
	parse->in++;
	parse->f.r = ft_atoi(rgb[0]);
	parse->f.g = ft_atoi(rgb[1]);
	parse->f.b = ft_atoi(rgb[2]);
	if (parse->f.r < 0 || parse->f.r > 255 || parse->f.g < 0 || parse->f.g > 255
		|| parse->f.b < 0 || parse->f.b > 255)
		return (free_matrix(rgb), ft_error("in colors\n"));
	return (0);
}

int	get_ceiling(t_parse *parse, char **rgb)
{
	if (parse->c.r != -1 || parse->c.g != -1 || parse->c.b != -1)
		return (free_matrix(rgb), ft_error("in colors\n"));
	parse->in++;
	parse->c.r = ft_atoi(rgb[0]);
	parse->c.g = ft_atoi(rgb[1]);
	parse->c.b = ft_atoi(rgb[2]);
	if (parse->c.r < 0 || parse->c.r > 255 || parse->c.g < 0 || parse->c.g > 255
		|| parse->c.b < 0 || parse->c.b > 255)
		return (free_matrix(rgb), ft_error("in colors\n"));
	return (0);
}
