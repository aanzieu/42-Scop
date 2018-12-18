/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:30:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/12 10:25:38 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

float		deg_to_rad(float deg)
{
	return (deg * ((float)M_PI / 180.0f));
}

void		find_point_min(float v, float *mm)
{
	if (v < *mm)
		*mm = v;
}

void		find_point_max(float v, float *mm)
{
	if (v > *mm)
		*mm = v;
}

void		matrix_debug(GLfloat const *matrix)
{
	dprintf(1, "%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t"
			"%f\t%f\n%f\t%f\t%f\t%f\n",
			matrix[0], matrix[1], matrix[2], matrix[3],
			matrix[4], matrix[5], matrix[6], matrix[7],
			matrix[8], matrix[9], matrix[10], matrix[11],
			matrix[12], matrix[13], matrix[14], matrix[15]);
}