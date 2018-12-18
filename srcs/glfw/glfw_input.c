/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:53:08 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 16:57:47 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	t_glenv *tmp_master;

	glViewport(0, 0, width, height);
	tmp_master = (t_glenv *)(glfwGetWindowUserPointer(window));
	free(tmp_master->projection);
	tmp_master->projection = mat4_perspective((60.0f * ((float)M_PI / 180.0f)),
			(float)width / (float)height, 0.1f, 1000.0f);
}

void		handle_scroll(GLFWwindow *window, double scroll_x, double scroll_y)
{
	t_glenv *tmp_master;

	tmp_master = (t_glenv *)(glfwGetWindowUserPointer(window));
	if (tmp_master->rotate)
		return ;
	tmp_master->model = mat4_scale(tmp_master->model,
			1.0f + (float)scroll_y / 10);
	(void)scroll_x;
}

void		handle_mouse_move(GLFWwindow *window, double pos_x, double pos_y)
{
	t_glenv *tmp_master;

	tmp_master = (t_glenv *)(glfwGetWindowUserPointer(window));
	if (!tmp_master->mouse_mov)
		return ;
	tmp_master->model = mat4_rotate_y(tmp_master->model,
			(tmp_master->mouse_pos.v[0] - pos_x) / 500.0f);
	tmp_master->model = mat4_rotate_x(tmp_master->model,
			(tmp_master->mouse_pos.v[1] - pos_y) / 500.0f);
	tmp_master->mouse_pos.v[0] = (float)pos_x;
	tmp_master->mouse_pos.v[1] = (float)pos_y;
	(void)window;
}

void		handle_keys(GLFWwindow *window, int button, int scancode,
		int action, int mods)
{
	t_glenv *tmp_master;
	GLfloat i[3];

	(void)window;
	(void)scancode;
	(void)mods;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	tmp_master = (t_glenv *)(glfwGetWindowUserPointer(window));
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_KEY_SPACE)
		{
			tmp_master->polygon_mode
				? glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)
				: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			tmp_master->polygon_mode = !tmp_master->polygon_mode;
		}
		handle_keys_options(tmp_master, button, window);
		if (tmp_master->rotate)
			return ;
		handle_keys_moov(tmp_master, button, i);
	}
}

void		glfw_controls(t_glenv *master)
{
	glfwSetFramebufferSizeCallback(master->win, framebuffer_size_callback);
	glfwSetKeyCallback(master->win, handle_keys);
	glfwSetScrollCallback(master->win, handle_scroll);
	glfwSetCursorPosCallback(master->win, handle_mouse_move);
}
