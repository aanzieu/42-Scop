/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:37:23 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 15:44:01 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

GLfloat			*mat3(void)
{
	GLfloat *matrix;

	matrix = (GLfloat *)calloc(9, sizeof(GLfloat));
	memset(matrix, 0, sizeof(GLfloat) * 9);
	matrix[0] = 1.0f;
	matrix[4] = 1.0f;
	matrix[8] = 1.0f;
	return (matrix);
}

GLfloat			*mat4(void)
{
	GLfloat *matrix;

	matrix = (GLfloat *)calloc(16, sizeof(GLfloat));
	memset(matrix, 0, sizeof(GLfloat) * 16);
	matrix[0] = 1.0f;
	matrix[5] = 1.0f;
	matrix[10] = 1.0f;
	matrix[15] = 1.0f;
	return (matrix);
}

GLfloat			*mat4_clone(GLfloat *matrix)
{
	GLfloat *new_matrix;

	new_matrix = mat4();
	memcpy(new_matrix, matrix, sizeof(GLfloat) * 16);
	free(matrix);
	return (new_matrix);
}
