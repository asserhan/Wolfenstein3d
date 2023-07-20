/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:58:11 by hasserao          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    if(!s1)
        return(-1);
	while ((*(unsigned char *)s1 || *(unsigned char *)s2))
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
			if (*(unsigned char *)s1 < *(unsigned char *)s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
int matrix_size(char **tab)
{
    int count;
    count =0;
    while(*tab)
    {
        count++;
        tab++;
    }
    return(count);
}
void print_matrix(char **tab)
{
    int i;
    int size = matrix_size(tab);
    i = 0;
    while(i < size)
    {
        ft_printf("%s\n",tab[i]);
        i++;
    }
}
void free_matrix(char **tab)
{
    int i;
    i = -1;
    while(++i)
        free(tab[i]);
    free(tab);
}