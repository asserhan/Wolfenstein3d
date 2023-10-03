/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:51 by hasserao          #+#    #+#             */
/*   Updated: 2023/10/03 16:32:18 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int north_path(t_parse *parse, char **tab, char *line)
{
	parse->in++;
	if (parse->no)
		return (free_matrix(tab), ft_error("in textures\n"));
	parse->no = check_path(line);
	if (!parse->no)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int south_path(t_parse *parse, char **tab, char *line)
{
	parse->in++;
	if (parse->so)
		return (free_matrix(tab), ft_error("in textures\n"));
	parse->so = check_path(line);
	if (!parse->so)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int west_path(t_parse *parse, char **tab, char *line)
{
	parse->in++;
	if (parse->we)
		return (free_matrix(tab), ft_error("in textures\n"));
	parse->we = check_path(line);
	if (!parse->we)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int east_path(t_parse *parse, char **tab, char *line)
{
	parse->in++;
	if (parse->ea)
		return (free_matrix(tab), ft_error("in textures\n"));
	parse->ea = check_path(line);
	if (!parse->ea)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int valid_comma(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}
