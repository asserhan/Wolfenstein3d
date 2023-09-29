/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:19:52 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 18:30:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_file(char *file)
{
	while (*file)
		file++;
	file--;
	if (*file != 'b' || *(file - 1) != 'u' || *(file - 2) != 'c' || *(file
			- 3) != '.')
		return (1);
	return (0);
}

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != '\t' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ' && c != '\n')
		return (1);
	return (0);
}

int	is_wall(char *line)
{
	while (*line)
	{
		if (*line == '0')
			return (1);
		line++;
	}
	return (0);
}

char	*skip_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

int	just_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}
