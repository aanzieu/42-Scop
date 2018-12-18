/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:38:30 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 15:26:57 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	cross(float *z, const float *x, const float *y)
{
	float t[3];

	t[0] = x[1] * y[2] - x[2] * y[1];
	t[1] = x[2] * y[0] - x[0] * y[2];
	t[2] = x[0] * y[1] - x[1] * y[0];
	z[0] = t[0];
	z[1] = t[1];
	z[2] = t[2];
}

void	normalize(float *v)
{
	float k;

	k = 1.0f / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] *= k;
	v[1] *= k;
	v[2] *= k;
}

void	normalize_vec3(struct s_vec3 v)
{
	float k;

	k = 1.0f / (float)sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]);
	v.v[0] *= k;
	v.v[1] *= k;
	v.v[2] *= k;
}

void	normal(float *n, const float *a,
		const float *b,
		const float *c)
{
	float u[3];
	float v[3];

	u[0] = b[0] - a[0];
	u[1] = b[1] - a[1];
	u[2] = b[2] - a[2];
	v[0] = c[0] - a[0];
	v[1] = c[1] - a[1];
	v[2] = c[2] - a[2];
	cross(n, u, v);
	normalize(n);
}
