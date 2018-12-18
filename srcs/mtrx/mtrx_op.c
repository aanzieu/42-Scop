/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:31:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 17:14:31 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

GLfloat			*normalize_mat4(GLfloat *m)
{
	GLfloat		*n;
	GLfloat		d;

	n = mat3();
	d = m[0] * m[5] * m[10]
		- m[0] * m[6] * m[9]
		+ m[1] * m[6] * m[8]
		- m[1] * m[4] * m[10]
		+ m[2] * m[4] * m[9]
		- m[2] * m[5] * m[8];
	if (fabs(d) > 0.f)
	{
		n[0] = -m[6] * m[9] + m[5] * m[10];
		n[1] = m[6] * m[8] - m[4] * m[10];
		n[2] = -m[5] * m[8] + m[4] * m[9];
		n[3] = m[2] * m[9] - m[1] * m[10];
		n[4] = -m[2] * m[8] + m[0] * m[10];
		n[5] = m[1] * m[8] - m[0] * m[9];
		n[6] = -m[2] * m[5] + m[1] * m[6];
		n[7] = m[2] * m[4] - m[0] * m[6];
		n[8] = -m[1] * m[4] + m[0] * m[5];
	}
	return (n);
}

GLfloat			*mat4_mult(GLfloat *dest, GLfloat *left, GLfloat *right)
{
	GLfloat		*final_matrix;
	unsigned	i;
	unsigned	j;

	final_matrix = mat4();
	i = 0;
	while (i < 16)
	{
		final_matrix[i] = 0;
		j = 0;
		while (j < 4)
		{
			final_matrix[i] += left[((i / 4) * 4 + j)] * right[(j * 4 + i % 4)];
			j++;
		}
		i++;
	}
	if (dest == NULL)
		return (mat4_clone(final_matrix));
	memcpy(dest, final_matrix, sizeof(GLfloat) * 16);
	free(final_matrix);
	return (dest);
}

GLfloat			*mat4_scale(GLfloat *dest, float amount)
{
	GLfloat		*scaling;

	scaling = mat4();
	scaling[0] = amount;
	scaling[5] = amount;
	scaling[10] = amount;
	if (dest == NULL)
		return (mat4_clone(scaling));
	dest = mat4_mult(dest, dest, scaling);
	free(scaling);
	return (dest);
}

GLfloat			*mat4_perspective(float fov, float aspect, float n, float f)
{
	GLfloat		*matrix;
	float		tangante;

	matrix = mat4();
	tangante = tanf(fov / 2.0f);
	matrix[0] = 1.0f / (aspect * tangante);
	matrix[5] = 1.0f / (tangante);
	matrix[10] = (f + n) / (f - n) * -1;
	matrix[11] = -1.0f;
	matrix[14] = (2.0f * f * n) / (f - n) * -1;
	return (matrix);
}
