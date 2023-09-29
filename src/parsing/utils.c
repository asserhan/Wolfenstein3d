/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:58:11 by hasserao          #+#    #+#             */
/*   Updated: 2023/09/29 16:54:55 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1)
		return (-1);
	while ((*(unsigned char *)s1 || *(unsigned char *)s2))
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

int	matrix_size(char **tab)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	free_matrix(char **tab)
{
	int	i;
	int	size;

	size = matrix_size(tab);
	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*check_path(char *line)
{
	char	*trim;

	trim = ft_strtrim(line, WHITE_SPACES);
	if (!trim)
		return (NULL);
	if (access(trim, F_OK | R_OK) == -1)
		return (free(trim), NULL);
	else
		return (trim);
}

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix_size(str))
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != ' ' && str[i][j] != '\t'
				&& str[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
