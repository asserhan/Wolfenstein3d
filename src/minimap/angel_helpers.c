/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angel_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:12:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/20 11:38:17 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	normalize_angle(double angle_radians)
{
	double	normalized_angle;

	normalized_angle = fmod(angle_radians, 2 * M_PI);
	if (normalized_angle < 0.0)
	{
		normalized_angle += 2 * M_PI;
	}
	return (normalized_angle);
}

int	is_face_up(double angle)
{
	if (angle >= 0 && angle <= M_PI)
		return (0);
	return (1);
}

int	is_face_right(double angle)
{
	if (angle >= M_PI_2 && angle <= 3 * M_PI_2)
		return (0);
	return (1);
}
int	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}