/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:39:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 17:55:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include <stdlib.h>
#include <time.h>

static void		check_arg(int ac, char **av, t_glenv *master)
{
	srand((unsigned int)time(NULL));
	master->mouse_pos.v[0] = 1.0f;
	master->mouse_pos.v[1] = 1.0f;
	master->polygon_mode = 0;
	master->mouse_mov = 0;
	master->texturing = 0;
	master->rotate = 0;
	if (ac == 2)
	{
		asprintf(&master->file_obj, "scenes/%s/%s.obj", av[1], av[1]);
		asprintf(&master->file_bmp, "scenes/wood.bmp");
	}
	else if (ac == 3)
	{
		master->file_obj = av[1];
		master->file_bmp = av[2];
	}
}

void			glfw_delete_buffer(t_obj *obj)
{
	if (obj->vbo)
		glDeleteBuffers(1, &obj->vbo);
	if (obj->vao)
		glDeleteVertexArrays(1, &obj->vao);
	obj->vbo = 0;
	obj->vao = 0;
}

void			glew_init(void)
{
	glewExperimental = 1;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}
}

void			glfw_create_program(t_glenv *master)
{
	GLuint vertexshader;
	GLuint fragmentshader;

	vertexshader = create_shader("./shader/vertex.glsl",
			GL_VERTEX_SHADER);
	fragmentshader = create_shader("./shader/fragment.glsl",
			GL_FRAGMENT_SHADER);
	master->shader_program = loadshaders(vertexshader, fragmentshader);
	glfw_matrix_init(master);
	display_command();
	glfw_render(master);
}

int				main(int ac, char **av)
{
	t_glenv master;

	if (ac != 2 && ac != 3)
		return (display_usage());
	check_arg(ac, av, &master);
	glfw_initialisation();
	glfw_window(&master);
	glfw_controls(&master);
	glew_init();
	if ((master.parser = obj_create(master.file_obj)) != NULL)
	{
		master.parser->vv != NULL ? glfw_create_program(&master)
			: dprintf(1, "not a good .obj File\n");
		glfwTerminate();
	}
	return (EXIT_FAILURE);
}
