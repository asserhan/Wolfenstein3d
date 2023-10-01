/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:51 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 17:38:18 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	north_path(t_parse *parse, char **tab)
{
	parse->in++;
	parse->no = check_path(tab[1]);
	if (!parse->no)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int	south_path(t_parse *parse, char **tab)
{
	parse->in++;
	parse->so = check_path(tab[1]);
	if (!parse->so)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int	west_path(t_parse *parse, char **tab)
{
	parse->in++;
	parse->we = check_path(tab[1]);
	if (!parse->we)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int	east_path(t_parse *parse, char **tab)
{
	parse->in++;
	parse->ea = check_path(tab[1]);
	if (!parse->ea)
		return (free_matrix(tab), ft_error("in textures\n"));
	return (0);
}

int	valid_comma(char *str)
{
	int	i;
	int	count;

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