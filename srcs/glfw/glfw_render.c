/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:59:44 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 16:16:31 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void		obj_render_surface(const t_obj *obj, int si)
{
	const struct s_obj_surf *sp;

	sp = obj->sv + si;
	if (0 < sp->poly_count)
	{
		if (sp->pibo)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sp->pibo);
			glDrawElements(GL_TRIANGLES, 3 * sp->poly_count,
					GL_UNSIGNED_INT, (const GLvoid *)0);
		}
	}
}

void		display_pointer(t_obj *obj, const size_t vs)
{
	if (obj->cloc >= 0)
	{
		glEnableVertexAttribArray(obj->cloc);
		glVertexAttribPointer(obj->cloc, 3, GL_FLOAT, GL_FALSE,
				vs, (const GLvoid *)0);
	}
	if (obj->nloc >= 0)
	{
		glEnableVertexAttribArray(obj->nloc);
		glVertexAttribPointer(obj->nloc, 3, GL_FLOAT, GL_FALSE,
				vs, (const GLvoid *)12);
	}
	if (obj->tloc >= 0)
	{
		glEnableVertexAttribArray(obj->tloc);
		glVertexAttribPointer(obj->tloc, 2, GL_FLOAT, GL_FALSE,
				vs, (const GLvoid *)24);
	}
	if (obj->vloc >= 0)
	{
		glEnableVertexAttribArray(obj->vloc);
		glVertexAttribPointer(obj->vloc, 3, GL_FLOAT, GL_FALSE,
				vs, (const GLvoid *)32);
	}
}

void		obj_initialize(t_obj *obj, int i)
{
	const size_t	vs = sizeof(struct s_obj_vert);
	const size_t	polygonshader = sizeof(struct s_obj_poly);

	if (obj->vao == 0)
	{
		glGenVertexArrays(1, &obj->vao);
		glBindVertexArray(obj->vao);
		glGenBuffers(1, &obj->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
		glBufferData(GL_ARRAY_BUFFER, obj->poly_count * vs,
				obj->vv, GL_STATIC_DRAW);
		while (++i < obj->surface_count)
		{
			if (obj->sv[i].poly_count > 0)
			{
				glGenBuffers(1, &obj->sv[i].pibo);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->sv[i].pibo);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER,
						obj->sv[i].poly_count * polygonshader,
						obj->sv[i].poly_vertx, GL_STATIC_DRAW);
			}
		}
		display_pointer(obj, vs);
	}
}

void		update_texture_transition(t_glenv *master)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	if (master->texturing)
	{
		if (master->parser->tlvl < 1.0f)
			master->parser->tlvl += 0.01f;
		else if (master->parser->tlvl > 1.0f)
			master->parser->tlvl = 1.0f;
	}
	else if (!master->texturing)
	{
		if (master->parser->tlvl > 0.0f)
			master->parser->tlvl -= 0.01f;
		else if (master->parser->tlvl < 0.0f)
			master->parser->tlvl = 0.0f;
	}
}

void		glfw_render(t_glenv *master)
{
	int si;

	glUseProgram(master->shader_program);
	glfw_get_uniforms(master);
	while (!glfwWindowShouldClose(master->win))
	{
		update_texture_transition(master);
		if (!master->rotate) {
			master->model = mat4_rotate_y(master->model, 0.01f);
		}
		glUniformMatrix4fv(master->uniform.projection_matrix, 1, GL_FALSE,
				master->projection);
		glUniformMatrix4fv(master->uniform.model_matrix, 1, GL_FALSE,
				master->model);
		glUniformMatrix4fv(master->uniform.view_matrix, 1, GL_FALSE,
				master->view);
		glUniform1f(master->uniform.texture_level, master->parser->tlvl);
		obj_initialize(master->parser, -1);
		glBindVertexArray(master->parser->vao);
		si = -1;
		while (++si < master->parser->surface_count)
			obj_render_surface(master->parser, si);
		glfwSwapBuffers(master->win);
		glfwPollEvents();
	}
}
