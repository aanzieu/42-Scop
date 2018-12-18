/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:14:18 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 15:59:57 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"
#include <float.h>

static void			init_min_vec3_max(struct s_vec3 *min, struct s_vec3 *max)
{
	min->v[0] = FLT_MAX;
	min->v[1] = FLT_MAX;
	min->v[2] = FLT_MAX;
	max->v[0] = FLT_MIN;
	max->v[1] = FLT_MIN;
	max->v[2] = FLT_MIN;
}

void			find_center_parse(t_glenv *master)
{
	int				i;
	struct s_vec3	min;
	struct s_vec3	max;
	// GLfloat			t[3];
	init_min_vec3_max(&min, &max);
	i = 0;
	while (i < master->parser->vm)
	{
		find_point_min(master->parser->vv[i].v[0], &min.v[0]);
		find_point_max(master->parser->vv[i].v[0], &max.v[0]);
		find_point_min(master->parser->vv[i].v[1], &min.v[1]);
		find_point_max(master->parser->vv[i].v[1], &max.v[1]);
		find_point_min(master->parser->vv[i].v[2], &min.v[2]);
		find_point_max(master->parser->vv[i].v[2], &max.v[2]);
		i++;
	}
	// t[0] = (-(max.v[0] + min.v[0]) / 2.0f);
	// t[1] = (-(max.v[1] + min.v[1]) / 2.0f);
	// t[2] = (-(max.v[2] + min.v[2]) / 2.0f);

	master->center.v[0] = (-(max.v[0] + min.v[0]) / 2.0f);
	master->center.v[1] = (-(max.v[1] + min.v[1]) / 2.0f);
	master->center.v[2] = (-(max.v[2] + min.v[2]) / 2.0f);
	master->translation = mat4_translate(NULL, master->center.v);
}

void				glfw_matrix_init(t_glenv *master)
{
	master->view = mat4();

	// master->translation = mat4();
	master->rotation = mat4();
	// master->scalling = mat4();
	master->scalling = mat4_scale(NULL, 0.2f);

	// master->scalling = mat4();
	master->model = mat4();
	find_center_parse(master);
	master->projection = mat4_perspective(deg_to_rad(60.0f),
			(float)WIDTH / (float)HEIGHT, 0.0f, 100.0f);
	master->model = mat4_mult(master->model, mat4_mult(master->model, master->translation, master->rotation), master->scalling);

}
