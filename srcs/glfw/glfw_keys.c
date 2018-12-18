/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:59:20 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 16:57:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	handle_keys_options(t_glenv *tmp_master, int button, GLFWwindow *window)
{
	if (button == GLFW_KEY_T)
		tmp_master->texturing = !tmp_master->texturing;
	else if (button == GLFW_KEY_R)
	{
		tmp_master->rotate = !tmp_master->rotate;
		tmp_master->mouse_mov = !tmp_master->mouse_mov;
	}
	else if (button == GLFW_KEY_X)
	{
		tmp_master->rotate = !tmp_master->rotate;
		tmp_master->mouse_mov = !tmp_master->mouse_mov;
	}
	if (button == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, 1);
}

void	handle_keys_moov2(t_glenv *tmp_master, int button, float i[3])
{
	if (button == GLFW_KEY_S)
	{
		i[1] = -0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
	else if (button == GLFW_KEY_Q)
	{
		i[2] = -0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
	else if (button == GLFW_KEY_E)
	{
		i[2] = 0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
}

void	handle_keys_moov(t_glenv *tmp_master, int button, float i[3])
{
	if (button == GLFW_KEY_A)
	{
		i[0] = -0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
	else if (button == GLFW_KEY_D)
	{
		i[0] = 0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
	else if (button == GLFW_KEY_W)
	{
		i[1] = 0.05f;
		tmp_master->view = mat4_translate(tmp_master->view, i);
	}
	handle_keys_moov2(tmp_master, button, i);
}
