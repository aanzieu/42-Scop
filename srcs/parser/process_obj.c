/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:36:57 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 14:35:34 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

int			search_index_set(t_obj *obj, const int i[3], int x)
{
	int y;

	y = obj->v_vertex[i[0]].index_vec3;
	while (y >= 0)
	{
		if (obj->v_indice[y].vertex_i == i[0]
				&& obj->v_indice[y].texture_i == i[1]
				&& obj->v_indice[y].normal_i == i[2])
		{
			obj->v_vertex[i[0]].index_vec3 = x;
			obj->v_indice[x].ii = y;
			obj->v_indice[x].vi = obj->v_indice[y].vi;
			break ;
		}
		y = obj->v_indice[y].ii;
	}
	return (y);
}

void		triangulate_indices(t_obj *obj, int ic, int index, int si)
{
	int	i;
	int	poly_indices;
	int	vertex_indices[3];

	i = 0;
	while (i < ic - 2)
	{
		if ((poly_indices = obj_add_poly(obj, si)) >= 0)
		{
			vertex_indices[0] = obj->v_indice[index].vi;
			vertex_indices[1] = obj->v_indice[index + i + 1].vi;
			vertex_indices[2] = obj->v_indice[index + i + 2].vi;
			obj_set_poly(obj, si, poly_indices, vertex_indices);
		}
		i++;
	}
}

void		random_vt(t_obj *obj, const int vi, float t[2])
{
	float random1;
	float random2;

	random1 = ((float)rand()) / (RAND_MAX + 1.0);
	random2 = ((float)rand()) / (RAND_MAX + 1.0);
	t[0] = random1;
	t[1] = random2;
	obj_set_vert_t(obj, vi, t);
}
