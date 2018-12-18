/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:04:25 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/12 08:56:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void		obj_set_vert_loc(t_obj *obj, int t, int v, int n)
{
	obj->tloc = t;
	obj->vloc = v;
	obj->nloc = n;
	glfw_delete_buffer(obj);
}

void		active_texture(t_glenv *master)
{
	if (master->bmp_data != NULL
			&& master->bmp_data->width > 0
			&& master->bmp_data->height > 0)
	{
		glGenTextures(1, &master->bmp_data->texture_id);
		glBindTexture(GL_TEXTURE_2D, master->bmp_data->texture_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, master->bmp_data->width,
				master->bmp_data->height,
				0, GL_BGR, GL_UNSIGNED_BYTE, master->bmp_data->image_bmp);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}


void		glfw_get_uniforms(t_glenv *master)
{
	master->bmp_data = load_texture(master);
	if (master->bmp_data != NULL)
		active_texture(master);
	master->uniform.texture_matrix = glGetUniformLocation(
			master->shader_program, "ourTexture");
	master->uniform.view_matrix = glGetUniformLocation(
			master->shader_program, "ViewMatrix");
	master->uniform.projection_matrix = glGetUniformLocation(
			master->shader_program, "ProjectionMatrix");
	master->uniform.model_matrix = glGetUniformLocation(
			master->shader_program, "ModelMatrix");
	master->uniform.texture_level = glGetUniformLocation(
			master->shader_program, "ourTextureLvl");
	glUniform1f(master->uniform.texture_level, master->parser->tlvl);
	obj_set_vert_loc(master->parser,
			glGetAttribLocation(master->shader_program, "vTexCoord"),
			glGetAttribLocation(master->shader_program, "vPosition"),
			glGetAttribLocation(master->shader_program, "vNormal"));
	master->parser->cloc = glGetAttribLocation(master->shader_program, "aColor");
	glEnable(GL_DEPTH_TEST);
}
