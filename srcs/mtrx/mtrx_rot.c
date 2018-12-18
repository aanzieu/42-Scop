/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:42:09 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 17:15:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

GLfloat	*mat4_rotate_x(GLfloat *dest, GLfloat amount)
{
	GLfloat	*rotation;

	rotation = mat4();
	rotation[5] = cosf(amount);
	rotation[6] = sinf(amount) * -1;
	rotation[9] = sinf(amount);
	rotation[10] = cosf(amount);
	if (dest == NULL)
		return (mat4_clone(rotation));
	dest = mat4_mult(dest, dest, rotation);
	free(rotation);
	return (dest);
}

GLfloat	*mat4_rotate_y(GLfloat *dest, GLfloat amount)
{
	GLfloat	*rotation;

	rotation = mat4();
	rotation[0] = cosf(amount);
	rotation[2] = sinf(amount);
	rotation[8] = sinf(amount) * -1;
	rotation[10] = cosf(amount);
	if (dest == NULL)
		return (mat4_clone(rotation));
	dest = mat4_mult(dest, dest, rotation);
	free(rotation);
	return (dest);
}

GLfloat	*mat4_rotate_z(GLfloat *dest, GLfloat amount)
{
	GLfloat	*rotation;

	rotation = mat4();
	rotation[0] = cosf(amount);
	rotation[1] = sinf(amount) * -1;
	rotation[4] = sinf(amount);
	rotation[5] = cosf(amount);
	if (dest == NULL)
		return (mat4_clone(rotation));
	dest = mat4_mult(dest, dest, rotation);
	free(rotation);
	return (dest);
}

GLfloat	*mat4_translate(GLfloat *dest, GLfloat amount[3])
{
	GLfloat	*translation;

	translation = mat4();
	translation[12] = amount[0];
	translation[13] = amount[1];
	translation[14] = amount[2];
	if (dest == NULL)
		return (mat4_clone(translation));
	dest = mat4_mult(dest, dest, translation);
	free(translation);
	return (dest);
}
